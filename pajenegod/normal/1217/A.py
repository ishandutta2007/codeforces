import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c = [int(x) for x in input().split()]
    a += c
    if a <= b:
        print 0
    else:
        # a - m > b + m
        # a - b > 2 * m
        m = min((a - b - 1)//2, c)
        print m + 1