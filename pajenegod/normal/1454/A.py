import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    print n, ' '.join(str(x) for x in range(1, n))