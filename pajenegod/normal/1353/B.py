import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]

    for _ in range(k):
        i = min(range(n), key = A.__getitem__)
        j = max(range(n), key = B.__getitem__)
        if A[i] < B[j]:
            A[i],B[j] = B[j],A[i]
    print sum(A)