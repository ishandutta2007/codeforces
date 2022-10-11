import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,m = [int(x) for x in input().split()]
    ans = [0, m, 2 * m]
    print ans[(n > 1) + (n > 2)]