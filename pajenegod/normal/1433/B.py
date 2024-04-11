import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    l = A.index(1)
    r = n - A[::-1].index(1)

    print r - l - sum(A[l:r])