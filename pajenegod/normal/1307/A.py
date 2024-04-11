import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,d = [int(x) for x in input().split()]
    A = [int(x) for x in input().split()]
    Asum = sum(A)
    while d and A[0] != Asum:
        i = 1
        while not A[i]: i += 1
        A[i - 1] += 1
        A[i] -= 1
        d -= 1
    print A[0]