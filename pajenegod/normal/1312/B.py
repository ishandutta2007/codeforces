import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    A.sort(reverse=True)
    print ' '.join(str(x) for x in A)