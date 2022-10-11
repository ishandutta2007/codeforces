import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    while n & 1 == 0:
        n //= 2
    if n != 1:
        print 'YES'
    else:
        print 'NO'