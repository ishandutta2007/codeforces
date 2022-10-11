import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    s = list(input())
    s.reverse()
    while s and s[-1] != '8':
        s.pop()

    if len(s)>=11:
        print 'YES'
    else:
        print 'NO'