import sys
range = xrange
input = raw_input

MOD = 10**9+7

big = 10**2 + 10
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
    return int(fac[n]*invfac[k]*invfac[n-k]%MOD)

n,m,k = [int(x) for x in input().split()]

count = [1 + (m - n - i + (n - 1))//n for i in range(n)]
count.insert(0, 0)

DP = [[0]*(k + 1) for _ in range(n + 1)]
DP[0][0] = 1

for i in range(1, n + 1):
    DPi = DP[i]
    DPim1 = DP[i - 1]
    
    for extra in range(min(n, k) + 1):
        c = pow(choose(n, extra), count[i], MOD)
        for j in range(k + 1 - extra):
            DPi[j + extra] = (DPi[j + extra] + int(DPim1[j] * c % MOD))%MOD

print DP[-1][-1]