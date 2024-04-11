import sys
range = xrange
input = raw_input

MOD = 998244353 
def red(x):
    return x if x < MOD else x - MOD

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
k = inp[ii]; ii += 1
m = inp[ii]; ii += 1

L = [x - 1 for x in inp[ii + 0: ii + 3 * m: 3]]
R = inp[ii + 1: ii + 3 * m: 3]
A = inp[ii + 2: ii + 3 * m: 3]

Lbuckets = [[] for _ in range(n + 1)]
Rbuckets = [[] for _ in range(n + 1)]
for i in range(m):
    Lbuckets[L[i]].append(i)
    Rbuckets[R[i]].append(i)

DP = [[0]*k for _ in range(n + 1)]
DP.append([1]*k)

Lind = [-1] * k
Rind = [0]  * k
marked = [1] * k
for i in range(n + 1):
    dp = DP[i]

    for ind in Lbuckets[i]:
        a = A[ind]
        r = R[ind]
        for j in range(k):
            if a & (1 << j) and Rind[j] < r:
                for x in range(Rind[j], r):
                    marked[j] = red(marked[j] + DP[x][j])
                Rind[j] = r
    for ind in Rbuckets[i]:
        a = A[ind]
        l = L[ind]
        for j in range(k):
            if not a & (1 << j) and Lind[j] < l:
                for x in range(Lind[j], l):
                    marked[j] = red(marked[j] - DP[x][j] + MOD)
                Lind[j] = l
    
    for j in range(k):
        if i == Rind[j]:
            dp[j] = marked[j]
            marked[j] = red(marked[j] + dp[j])
            Rind[j] += 1

prod = 1
for j in range(k):
    prod = prod * DP[n][j] % MOD

print prod