import sys
range = xrange
input = raw_input


t = int(input())
for _ in range(t):
    n = int(input())
    A = [1,8]
    for _ in range(n - 2):
        A.append(A[-1] + 8)
    ans = sum(A[i] * i for i in range(n//2 + 1))
    print ans