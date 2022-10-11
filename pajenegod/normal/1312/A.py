import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    m,n = [int(x) for x in input().split()]
    if m % n == 0:
        print 'YES'
    else:
        print 'NO'