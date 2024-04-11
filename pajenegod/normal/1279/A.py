import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    r,g,b = sorted([int(x) for x in input().split()])

    b -= 1
    r,g,b = sorted((r,g,b))

    if r + g >= b:
        print 'Yes'
    else:
        print 'No'