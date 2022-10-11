import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    if all((x & 1) == (A[0] & 1) for x in A):
        print 'YES'
    else:
        print 'NO'