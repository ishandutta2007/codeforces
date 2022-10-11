import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    if sum(a&1 for a in A) == n:
        print 'Yes'
    else:
        print 'No'