import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b = sorted(int(x) for x in input().split())
    c,d = sorted(int(x) for x in input().split())
    if b == d and a + c == b:
        print 'YES'
    else:
        print 'NO'