/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once

#include "Module.h"

namespace WPEFramework {
namespace Exchange {
    // @json
    struct EXTERNAL IAmazonPrime : virtual public Core::IUnknown {

        enum { ID = ID_AMAZONPRIME };

        enum state : uint8_t {
            FOREGROUND = 1,
            FOREGROUND_UNFOCUSED = 2,
            BACKGROUND = 3 ,
            EXIT = 4,
            UNKNOWN = 5
        };

        /* @event */
        struct EXTERNAL INotification : virtual public Core::IUnknown {
            enum { ID = ID_AMAZONPRIME_NOTIFICATION };

            // @brief Receive a message from the generic message bus
            // @param the message that was received.
            virtual void Receive(const string& message) = 0;

            // @brief The state has been changed 
            virtual void StateChanged() = 0;
        };

        virtual void Register(IAmazonPrime::INotification* ignition) = 0;
        virtual void Unregister(IAmazonPrime::INotification* ignition) = 0;

        // @brief  Send a message to the message bus
        virtual void Send(const string& message) = 0;

        // @property
        // @brief Control ignition life cycle
        // @param State we need to move to
        // @retval ERROR_GENERAL Failed to set/retrieve muting state
        virtual uint32_t State(const IAmazonPrime::state state)  = 0;
        virtual uint32_t State(IAmazonPrime::state& state /* @out */) const = 0;
    };
}
}
