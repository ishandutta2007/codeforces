import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in reversed(input().split())]

A = [A[i] - i for i in range(n)]
A.sort(reverse=True)

A = [A[i] + i for i in range(n)]

if A == sorted(A, reverse=True) and not any(a < 0 for a in A):
    print ' '.join(str(a) for a in reversed(A))
else:
    print ':('