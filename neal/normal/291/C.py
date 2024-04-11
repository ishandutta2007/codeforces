import sys

N, K = map(int, raw_input().split())
IPs = []

for i in xrange(N):
    IP = map(int, raw_input().split('.'))
    IPs.append((IP[0] << 24) + (IP[1] << 16) + (IP[2] << 8) + IP[3])

for ones in xrange(1, 32):
    subnet = ((1 << ones) - 1) << (32 - ones)
    networks = set()

    for i in xrange(N):
        networks.add(IPs[i] & subnet)

    if len(networks) == K:
        print '.'.join(map(str, [subnet >> 24, (subnet >> 16) & 255, (subnet >> 8) & 255, subnet & 255]))
        sys.exit(0)

print -1