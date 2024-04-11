import sys
range = xrange
input = raw_input

MOD = 998244353 

n,n = [int(x) for x in input().split()]
C = [int(x) - 1 for x in input().split()]

pos = [0]*n
for i in range(n):
    pos[C[i]] = i

DP = [[1]*(n + 1) for _ in range(n + 1)]
for le in range(1, n + 1):
    for i in range(n - le + 1):
        j = i + le
        k = min(range(i,j), key = C.__getitem__)
        
        ans1 = 0
        for split in range(i,k + 1):
            ans1 += DP[i][split] * DP[split][k] % MOD   
        
        ans2 = 0
        for split in range(k+1, j + 1):
            ans2 += DP[k + 1][split] * DP[split][j] % MOD

        DP[i][j] = int((ans1 % MOD) * (ans2 % MOD) % MOD)

print DP[0][n]