import sys
range = xrange
input = raw_input

def solve(A):
    n = len(A)
    if n == 0:
        return 0
    assert n & 1 == 0
    B = []
    for i in range(0, n, 2):
        B.append(-A[i] + A[i + 1])
    n = len(B)

    S = [0]
    for b in B:
        S.append(S[-1] + b)

    minn = 0
    best = 0
    for i in range(n):
        minn = min(minn, S[i + 1])
        best = max(best, S[i + 1] - minn)
    return best

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    if n & 1:
        print sum(A[::2]) + max(solve(A[1:][::-1]), solve(A[:-1]))
    else:
        print sum(A[::2]) + max(solve(A), solve(A[1:-1][::-1]))