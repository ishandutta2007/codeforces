import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,x = [int(x) for x in input().split()]
    s = input()

    cumsum = [0]
    for c in s:
        cumsum.append(cumsum[-1] + 1 - 2 * (ord(c) - 48))

    period = cumsum[-1]
    if period == 0:
        if x in cumsum:
            print -1
        else:
            print 0
    else:
        ans = 0
        for y in cumsum[:-1]:
            # x - y = period * t, t >= 0
            if (x - y) % period == 0 and (x - y) // period >= 0:
                ans += 1
        print ans