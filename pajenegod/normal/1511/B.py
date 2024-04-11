import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c = [int(x) - 1 for x in input().split()]

    x = 10**a
    y = 10**b

    if c != a and c != b:
        if a <= b:
            x += 10**c
        else:
            y += 10**c

    print x,y