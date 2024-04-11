import sys
range = xrange
input = raw_input

rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]

t = int(input())
for _ in range(t):
    n = rint()
    i = 0
    out = []
    while n:
        x = (n // (10**i)) % 10
        if x:
            n -= x * 10**i
            out.append(x * 10**i)
        i += 1
    print len(out)
    print ' '.join(str(x) for x in out)