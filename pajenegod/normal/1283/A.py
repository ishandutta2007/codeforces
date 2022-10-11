import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    h,m = [int(x) for x in input().split()]

    t = 0
    if m > 0:
        h += 1
        t += (60 - m)
    print t + 60*(24 - h)