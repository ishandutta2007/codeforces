import sys
range = xrange
input = raw_input

MOD = 10**9+7

import __pypy__
modmul = __pypy__.intop.int_mulmod
mo = lambda i,j: modmul(i, j, MOD)


big = 10**6
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
    if k < 0 or k > n:
        return 0
    return mo(mo(fac[n], invfac[k]), invfac[n-k])

inp = sys.stdin.read().split(); ii = 0
n = int(inp[ii]); ii += 1
T = int(inp[ii]); ii += 1

N = 0
K = 0
val = 1

ans = 0
for _ in range(n):
    t = int(inp[ii]); ii += 1
    T -= t
    if T < 0:
        break
    
    val += val - choose(N, K)
    N += 1

    goalK = min(T, N)
    while K < goalK:
        K += 1
        val += choose(N, K)

    while K > goalK:
        val -= choose(N, K)
        K -= 1

    #print val, sum(choose(N, i) for i in range(K + 1))
    val %= MOD
    ans += mo(pow(modinv[2], N, MOD), val)
print ans % MOD