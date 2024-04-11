import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x1,p1 = [int(x) for x in input().split()]
    x2,p2 = [int(x) for x in input().split()]

    d = min(p1, p2)
    p1 -= d
    p2 -= d

    if p1 > 10:
        print '>'
    elif p2 > 10:
        print '<'
    else:
        a = x1 * 10**p1
        b = x2 * 10**p2
        if a == b:
            print '='
        elif a < b:
            print '<'
        else:
            print '>'