import sys
range = xrange
input = raw_input
MOD = 10**9 + 7
n, m = [int(x) for x in input().split()]

big = 1001

DP = [[0]*big for _ in range(m)]
DP[0] = [1] * big
for i in range(1, m):
    prevDP = DP[i - 1]
    dp = DP[i]

    s = 0
    for j in range(big):
        dp[j] = s = (s + prevDP[j]) % MOD
dp = DP[-1]

ways = 0
for i in range(1, n + 1):
    for j in range(i, n + 1):
        ways = (ways + dp[i - 1] * dp[n - j]) % MOD

print ways