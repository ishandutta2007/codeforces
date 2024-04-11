import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    r,b,d = [int(x) for x in input().split()]

    if r < b:
        r,b = b,r
    
    if (r + d) // (d + 1) <= b:
        print 'YES'
    else:
        print 'NO'