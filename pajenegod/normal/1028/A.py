import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

count = 0
xsum = 0
ysum = 0

for y in range(n):
    for x,c in enumerate(input()):
        if c=='B':
            count += 1
            xsum += x
            ysum += y
print 1+ysum//count, 1+xsum//count