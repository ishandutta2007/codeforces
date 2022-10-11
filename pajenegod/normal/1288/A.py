import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,d = [int(x) for x in input().split()]

    pos = False
    i = 1
    while i * i <= d:
        x = i - 1
        pos |= x + (d + x) // (x + 1) <= n
        i += 1

    if pos:
        print 'YES'
    else:
        print 'NO'