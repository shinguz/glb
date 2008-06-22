/*
 * Copyright (C) 2008 Codership Oy <info@codership.com>
 *
 * $Id$
 */

#ifndef _glb_socket_h_
#define _glb_socket_h_

#include <stdbool.h>
#include <string.h> // for memcmp() and stuff
#include <netinet/in.h>

typedef struct sockaddr_in glb_sockaddr_t;

static inline bool
glb_socket_addr_is_equal (glb_sockaddr_t* left, glb_sockaddr_t* right)
{
    return (!memcmp(left, right, sizeof (glb_sockaddr_t)));
}

// behaves like inet_ntoa() - returns static buffer
extern const char*
glb_socket_addr_to_string (glb_sockaddr_t* addr);
 
// Fill-in struct in_addr given hostname
// @return negative error code in case of failure
extern int
_glb_socket_in_addr (struct in_addr* addr, const char* hostname);

// Fill-in struct sockaddr_in given in_addr and port
extern void
_glb_socket_sockaddr_in (struct sockaddr_in* name,
                        struct in_addr*     host,
                        uint16_t            port);

// Initialize glb_sockaddr_t struct
extern long
glb_socket_addr_init (glb_sockaddr_t* addr,
                      const char*     hostname,
                      uint16_t        port);

extern void
glb_socket_addr_set_port (glb_sockaddr_t* addr, uint16_t port);

extern short
glb_socket_addr_get_port (glb_sockaddr_t* addr);

// Returns socket (file descriptor) bound to a given address.
extern int
glb_socket_create (glb_sockaddr_t* addr);

#endif // _glb_socket_h_