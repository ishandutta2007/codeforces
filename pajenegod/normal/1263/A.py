import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    r,g,b = sorted(int(x) for x in input().split())

    diff1 = g - r

    cand = 2 * diff1
    g -= diff1
    b -= diff1

    a = r + g
    diff = a - b
    if diff > 0:
        cand += (diff//2) * 2
        a -= (diff//2) * 2
    cand += 2 * min(a,b)
    print cand//2