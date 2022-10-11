import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x,y = [int(x) for x in input().split()]
    z = x - y
    print 'YES' if (z == 0 or z > 1) else 'NO'