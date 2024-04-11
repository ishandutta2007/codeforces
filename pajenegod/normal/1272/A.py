import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c = [int(x) for x in input().split()]

    opt = 1e18
    for dx in -1,0,1:
        for dy in -1,0,1:
            for dz in -1,0,1:
                x = a + dx
                y = b + dy
                z = c + dz
                opt = min(opt, abs(x - y) + abs(x - z) + abs(y - z))
    print opt