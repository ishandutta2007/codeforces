import sys
sys.setrecursionlimit(2100)
range = xrange
input = raw_input

def getter(DP, n, k):
    if 2 * k >= n:
        k = n - k
    if k < 0:
        return 0
    return DP[k]

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
k = inp[ii]; ii += 1

DP = [1]
DPk = []
DPkm1 = []
for N in range(1, 2002):
    DPk.append(getter(DP, N - 1, k))
    DPkm1.append(getter(DP, N - 1, k-1))
    DP = [getter(DP, N - 1, K) + getter(DP, N - 1, K - 1) for K in range((N >> 1) + 1)]

sm = [0]*(n+2)
cnt = [0]*(n+2)
 
for i in range(1, n):
    for j in range(i+1, n+1):
        x = inp[ii]; ii += 1
        if x != -1:
            cnt[i] += 1
            cnt[j] += 1
            sm[i] += x
            sm[j] += x
ans = 0
for i in range(1, n+1):
	ans += sm[i]*DPkm1[cnt[i] - 1]
print ans // DPk[n]