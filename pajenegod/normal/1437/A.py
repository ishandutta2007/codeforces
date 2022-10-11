import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    l,r = [int(x) for x in input().split()]

    if r + 1 <= 2 * l:
        print 'YES'
    else:
        print 'NO'