import sys
range = xrange
input = raw_input
import __pypy__
mulmod = __pypy__.intop.int_mulmod
 
MOD = 10**9+7
n, k = [int(x) for x in input().split()]

# goal is to calculate
#def f(n, k):
#    s = 0
#    for i in range(n + 1):
#        s += pow(i,k,MOD)
#        s %= MOD
#    return s
 
def interpolate(samples, x):
    x %= MOD
    m = len(samples)
    if x < m:
        return samples[x]
    
    modinv = [1]*m
    for i in range(2, m):
        modinv[i] = mulmod(-(MOD//i), modinv[MOD%i], MOD)
 
    invfac = [1]
    for i in range(1, m):
        invfac.append(mulmod(invfac[-1], modinv[i], MOD))
    invneg_fac = [invfac[i] * (1 - 2 * (i & 1)) for i in range(m)]
 
    xfac_down = [1]
    for j in reversed(range(x - (m - 1), x + 1)):
        xfac_down.append(mulmod(xfac_down[-1], j, MOD))
    
    xfac_up = [1]
    for j in range(x - (m - 1), x + 1):
        xfac_up.append(mulmod(xfac_up[-1], j, MOD))
    
    s = 0
    for i, pr in enumerate(samples):
        pr = mulmod(pr, xfac_down[i], MOD)
        pr = mulmod(pr, xfac_up[m - 1 - i], MOD)
        pr = mulmod(pr, invfac[i], MOD)
        pr = mulmod(pr, invneg_fac[m - i - 1], MOD)
        s = (s + pr) % MOD
    return s
 
samples = [0]
for i in range(k + 1):
    samples.append((samples[-1] + pow(i, k, MOD)) % MOD)

ans = interpolate(samples, n + 1)

if k == 0:
    # my code assumes 0**0 is 1, the problem doesn't
    print (ans - 1) % MOD
else:
    print ans