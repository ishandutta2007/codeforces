import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c = [int(x) for x in input().split()]
    x = y = -1
    if a < c:
        x = 1

    if b * a > c:
        y = b
    print x,y