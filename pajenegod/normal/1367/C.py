import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    A = [int(c) for c in input()]
    prev = sum(A)
    s = 0
    for i in range(min(k, n)):
        s += A[i]
    for i in range(n):
        if i + k < n:
            s += A[i + k]
        if s == 0:
            A[i] = 1
            s += 1

        if 0 <= i - k:
            s -= A[i - k]
    print sum(A) - prev