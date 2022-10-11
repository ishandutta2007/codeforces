import sys
range = xrange
input = raw_input

MOD = 998244353
import __pypy__
modmult = __pypy__.intop.int_mulmod
mo = lambda a,b: modmult(a,b,MOD)
red = lambda a: a if a < MOD else a - MOD

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
    if n < k or k < 0:
        return 0
    return mo(mo(fac[n], invfac[k]), invfac[n-k])

n,k = [int(x) for x in input().split()]

ans = 0
for divs in range(1, n + 1):
    ans = red(ans + choose((n // divs) - 1, k - 1))
print ans