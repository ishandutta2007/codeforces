import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    s = int(input())
    t = 0
    while s >= 10:
        a,b = divmod(s,10)
        t += a * 10
        s = a + b
    print s + t