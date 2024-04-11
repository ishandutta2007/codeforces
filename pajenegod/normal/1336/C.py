import sys
range = xrange
input = raw_input

MOD = 998244353
def modder(x):
    return x if x < MOD else x - MOD

S = input()
T = input()

n = len(S)
m = len(T)

DP = [[0]*n for _ in range(n + 1)]

c = S[0]
for i in range(n):
    DP[1][i] = 2 * (i >= m or c == T[i])

for l in range(1, n):
    DPl = DP[l]
    DPlp1 = DP[l + 1]

    for i in range(n - l + 1):
        c = S[l]
        if i and (i - 1 >= m or T[i - 1] == c):
            DPlp1[i - 1] = modder(DPlp1[i - 1] + DPl[i])

        if i + l < n and (i + l >= m or T[i + l] == c):
            DPlp1[i] += modder(DPlp1[i] + DPl[i])

print sum(DP[j][0] for j in range(m, n + 1)) % MOD