import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    if n % 4:
        print 'NO'
    else:
        print 'YES'