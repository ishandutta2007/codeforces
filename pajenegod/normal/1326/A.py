import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    if n <= 1:
        print -1
    else:
        s = '2' + '3'*(n - 1)
        print s