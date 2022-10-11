from collections import defaultdict as di
import sys
range = xrange
input = raw_input

MOD = 10**9+7

big = 10**5 + 10
modinv = [1]*big
for i in range(2,big):
    modinv[i] = int((-(MOD//i)*modinv[MOD%i])%MOD)

fac = [1]
for i in range(1,big):
    fac.append(int(fac[-1]*i%MOD))

invfac = [1]
for i in range(1,big):
    invfac.append(int(invfac[-1]*modinv[i]%MOD))

def choose(n,k):
    return fac[n]*invfac[k]*invfac[n-k]%MOD



inp = sys.stdin.read().split()
ii = 0

n = int(inp[ii])
ii += 1

k = int(inp[ii])
ii += 1

count = di(int)
extra = 0
for _ in range(n):
    if all(c=='4' or c=='7' for c in inp[ii]):
        count[inp[ii]] += 1
    else:
        extra += 1
    ii += 1

A = []
for v in count.values():
    if v > 1:
        A.append(v)
    else:
        extra += 1

m = len(A)
DP = [1]
for a in A:
    if len(DP) <= k:
        DP.append(0)
    for i in reversed(range(1, len(DP))):
        DP[i] = int((DP[i] + a * DP[i - 1]) % MOD)

ans = 0
for i in range(max(k - extra, 0), len(DP)):
    ans += DP[i] * choose(extra, k - i) % MOD

print ans % MOD