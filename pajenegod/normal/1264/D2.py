import sys
range = xrange
input = raw_input

import __pypy__
mulmod = __pypy__.intop.int_mulmod

MOD = 998244353  
half = pow(2, MOD - 2, MOD)

S = input()
n = len(S)
A = []
for c in S:
    if c == '?':
        A.append(0)
    elif c == '(':
        A.append(1)
    else:
        A.append(2)


big = 10**6 + 10
modinv = [1]*big
for i in range(2,big):
    modinv[i] = mulmod(-(MOD//i), modinv[MOD%i], MOD)

fac = [1]
for i in range(1,big):
    fac.append(mulmod(fac[-1], i, MOD))

invfac = [1]
for i in range(1,big):
    invfac.append(mulmod(invfac[-1], modinv[i], MOD))

def choose(n,k):
    if k > n:
        return 0
    return mulmod(mulmod(fac[n], invfac[k], MOD), invfac[n-k], MOD)

count = sum(1 for a in A if a == 0)

cumsum0 = [0]
for k in range(n + 1):
    cumsum0.append((cumsum0[-1] + choose(count - 1, k)) % MOD)

cumsum1 = [0]
for k in range(n + 1):
    cumsum1.append((cumsum1[-1] + choose(count, k)) % MOD)

ans = 0
m = sum(1 for a in A if a != 1)
for i in range(n):
    m -= A[i] != 1
    if A[i] == 0 and m >= 0:
        ans = (ans + cumsum0[m]) % MOD
    elif A[i] == 1 and m >= 0:
        ans = (ans + cumsum1[m]) % MOD
    m -= A[i] == 1
print ans