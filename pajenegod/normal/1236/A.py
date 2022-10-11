import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c = [int(x) for x in input().split()]

    best = 0
    for k in range(min(b, c//2) + 1):
        _a = a
        _b = b - k
        _c = c - 2 * k

        best = max(best, 3 * k + 3 * min(_a, _b//2))
    print best