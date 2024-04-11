import sys
range = xrange
input = raw_input

MOD = 998244353

n = int(input())
A = []
for _ in range(n):
    S = input()
    if S[0] == '+':
        A.append(int(S[2:]))
    else:
        A.append(-1)

def DP1(A):
    n = len(A)
    m = sum(A)
    DP = [[0] * (m + 1) for _ in range(n + 1)]
    DP[-1][0] = 1

    for i in range(n):
        DP[i][:] = DP[i - 1]

        if A[i] == 1:
            for j in range(m):
                DP[i][j + 1] = (DP[i][j + 1] + DP[i - 1][j]) % MOD
        else:
            DP[i][0] = (DP[i][0] + DP[i - 1][0]) % MOD
            for j in range(m):
                DP[i][j] = (DP[i][j] + DP[i - 1][j + 1]) % MOD
    return DP[n - 1]

def DP2(A, B):
    n = len(A)
    m = len(B) + sum(A)
    DP = [[0] * (m + 1) for _ in range(n + 1)]
    DP[-1][:len(B)] = B

    for i in range(n):
        DP[i][:] = DP[i - 1]

        if A[i] == 1:
            for j in range(m):
                DP[i][j + 1] = (DP[i][j + 1] + DP[i - 1][j]) % MOD
        else:
            for j in range(m):
                DP[i][j] = (DP[i][j] + DP[i - 1][j + 1]) % MOD
    return DP[n - 1]

ans = 0

for i in range(n):
    if A[i] >= 0:
        A1 = [+(a>=0) for a in A[:i] if a<=A[i]]
        A2 = [+(a>=0) for a in A[i+1:] if a<A[i]]

        extra = len(A) - 1 - len(A1) - len(A2)
        
        ans += pow(2, extra, MOD) * sum(DP2(A2, DP1(A1))) * A[i]


print ans % MOD