import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    print sum(int(x) for x in input().split())