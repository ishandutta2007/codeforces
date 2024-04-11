import sys
range = xrange
input = raw_input

MOD = 998244353

big = 10**6
DP0 = [-1] * big
DP1 = [-1] * big

DP0[0] = DP0[1] = DP1[0] = DP1[1] = 0
DP0[2] = DP1[2] = 1

for n in range(3, big):
    DP0[n] = (
        #0
        + DP0[n - 1]
        #01
        + DP0[n - 2]
        #11
        + DP0[n - 2] + pow(2, n - 2, MOD)
        ) % MOD
#    DP1[n] = (
#        #0
#        + DP1[n - 1]
#        #01
#        + DP1[n - 2]
#        #11
#        + DP1[n - 2] + pow(2, n - 2, MOD)
#        #011 (not using last)
#        + 0
#        #111 (not using last)
#        + DP0[n - 3] + pow(2, n - 3, MOD)
#        ) % MOD    


inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
m = int(inp[ii]); ii += 1

A = []
for _ in range(n):
    A.append(inp[ii]); ii += 1

whites = 0
for a in A:
    whites += a.count('o')

cost = 0

for i in range(n):
    j = 0
    while j < m:
        if A[i][j] == '*':
            j += 1
        else:
            r = j
            while r < m and A[i][r] == 'o':
                r += 1
            
            N = r - j
            cost = (cost + DP0[N] * pow(2, whites - N, MOD) % MOD) % MOD
            j = r

for i in range(m):
    j = 0
    while j < n:
        if A[j][i] == '*':
            j += 1
        else:
            r = j
            while r < n and A[r][i] == 'o':
                r += 1
            
            N = r - j
            cost = (cost + DP0[N] * pow(2, whites - N, MOD) % MOD) % MOD
            j = r

print cost % MOD