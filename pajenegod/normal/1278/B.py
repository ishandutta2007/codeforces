import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b = [int(x) for x in input().split()]
    a -= b
    if a < 0:
        a = -a

    i = 1
    while a > 0 or a&1:
        a -= i
        i += 1

    print i - 1