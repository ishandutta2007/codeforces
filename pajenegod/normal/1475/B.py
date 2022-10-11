import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    while n >= 0:
        if n % 2021 == 0:
            print 'YES'
            break
        n -= 2020
    else:
        print 'NO'