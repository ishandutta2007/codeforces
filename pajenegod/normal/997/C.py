import sys
range = xrange
input = raw_input

MOD = 998244353 

import __pypy__
modmul = __pypy__.intop.int_mulmod
mo = lambda a,b: modmul(a,b,MOD)
po = lambda a,b: pow(a,b,MOD)

big = 10**6 + 10
modinv = [1]*big
for i in range(2,big):
    modinv[i] = mo(-(MOD//i), modinv[MOD%i])

fac = [1]
for i in range(1,big):
    fac.append(mo(fac[-1], i))

invfac = [1]
for i in range(1,big):
    invfac.append(mo(invfac[-1], modinv[i]))

def choose(n,k):
    return mo(mo(fac[n], invfac[k]), invfac[n-k])

def par(x):
    return -1 if x & 1 else 1

n = int(input())

ans = 0
extra = 0
for i in range(1, n + 1):
    base = po(3, n - i)
    tmp = po(-base + 1, n) - po(-base, n)
    ans = (ans + par(i + 1 + n) * mo(choose(n, i), tmp)) % MOD
    
    exp = modmul(n, n - i, MOD - 1) + i
    extra = (extra + par(i + 1) * mo(choose(n, i), po(3, exp))) % MOD

print (3 * ans + 2 * extra) % MOD