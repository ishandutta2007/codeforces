import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

A.sort()

if sum(A[:n]) != sum(A[n:]):
    print ' '.join(str(a) for a in A)
else:
    print -1