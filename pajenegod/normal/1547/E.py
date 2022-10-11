import sys
input = sys.stdin.readline

def solve(n, A, T):
    DP = [2 * 10**9] * n
    for j in range(len(A)):
        DP[A[j]] = T[j]
    
    for i in range(1, n):
        DP[i] = min(DP[i], DP[i - 1] + 1)

    return DP



t = int(input())
for _ in range(t):
    input()

    n,k = [int(x) for x in input().split()]
    A = [int(x) - 1 for x in input().split()]
    T = [int(x) for x in input().split()]

    DPleft = solve(n, A, T)
    DPright = solve(n, [n - 1 - a for a in A], T)[::-1]


    DP = [min(dp1, dp2) for dp1, dp2 in zip(DPleft, DPright)]

    print ' '.join(str(x) for x in DP)