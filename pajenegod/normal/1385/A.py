import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x,y,z = [int(x) for x in input().split()]
    maxx = max(x,y,z)
    count = (maxx == x) + (maxx == y) + (maxx == z)
    if count == 1:
        print 'NO'
    elif count == 3:
        print 'YES'
        print x,x,x
    else:
        minx = min(x,y,z)
        if x == y:
            a = maxx
            b = c = minx
        elif x == z:
            b = maxx
            a = c = minx
        else:
            c = maxx
            a = b = minx
        print 'YES'
        print a,b,c
        assert x == max(a,b)
        assert y == max(a,c)
        assert z == max(b,c)