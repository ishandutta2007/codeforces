import sys
from collections import defaultdict
range = xrange
input = raw_input

def fast_modder(MOD):
    """ Returns function modmul(a,b,c=0) that quickly calculates (a * b + c) % MOD, assuming 0 <= a,b < MOD """
    import sys, platform
    impl = platform.python_implementation()
    maxs = sys.maxsize
    if 'PyPy' in impl and MOD <= maxs and MOD ** 2 > maxs:
        import __pypy__
        intsub = __pypy__.intop.int_sub
        intmul = __pypy__.intop.int_mul
        intmulmod = __pypy__.intop.int_mulmod
        if MOD < 2**30 - 1000:
            MODINV = 1.0 / MOD
            def modmul(a, b, c=0):
                return (intsub(intmul(a,b), intmul(MOD, int(MODINV * a * b))) + c) % MOD
        else:
            def modmul(a, b, c=0):
                return (intmulmod(a, b, MOD) + c) % MOD
    else:
        def modmul(a, b, c=0):
            return (a * b + c) % MOD
    return modmul


""" Precalculate factorial, modular inverse of factorial and modular inverse """
MOD = 10 ** 9 + 7 # needs to be prime!
maxN = 10 ** 6
modmul = fast_modder(MOD)

def mod_precalc():
    """ Calculates fac, inv_fac and mod_inv for i < maxN in O(maxN) time """
    assert maxN <= MOD
    
    fac = [1] * maxN
    for i in range(2, maxN):
        fac[i] = modmul(fac[i - 1], i)

    inv_fac = [pow(fac[-1], MOD - 2, MOD)] * maxN
    for i in reversed(range(1, maxN)):
        inv_fac[i - 1] = modmul(inv_fac[i], i)

    inv_mod = [modmul(inv_fac[i], fac[i - 1]) for i in range(maxN)]

    return fac, inv_fac, inv_mod

fac, inv_fac, inv_mod = mod_precalc()

""" Useful functions involving modulo """

def choose(n,k):
    """ Calculate n choose k in O(1) time """
    if k < 0 or k > n:
        return 0
    return modmul(modmul(fac[n], inv_fac[k]), inv_fac[n-k])

def matrix_modmul(A, B):
    """ Multiplies matrices A and B, assuming 0 <= A[i][j], B[i][j] < MOD """
    assert len(A[0]) == len(B)
    C = []
    for Ai in A:
        tmp = [0] * len(B[0])
        for k in range(len(B)):
            Aik = Ai[k]
            Bk = B[k]
            for j in range(len(Bk)):
                tmp[j] = modmul(Aik, Bk[j], tmp[j])
        C.append(tmp)
    return C


n = int(input())
A = [int(x) for x in input().split()]

Asum = sum(A)
if Asum % n != 0:
    print 0
    sys.exit()

goal = Asum // n

if all(a == goal for a in A):
    print 1
    sys.exit()

sinks = [i for i in range(n) if A[i] < goal]
sources = [i for i in range(n) if A[i] > goal]

def solve(sinks, sources):
    si = len(sinks)
    so = len(sources)

    factor = si if so == 1 else 1

    ans = modmul(modmul(modmul(modmul(factor, fac[si]), fac[so]), choose(n, si + so)), fac[n - si - so])

    def counters(B):
        counter = defaultdict(int)
        for i in B:
            counter[A[i]] += 1
        return [counter[a] for a in counter]

    for c in counters(sinks):
        ans = modmul(ans, inv_fac[c])

    for c in counters(sources):
        ans = modmul(ans, inv_fac[c])

    ans = modmul(ans, inv_fac[n - si - so])

    return ans

print (solve(sinks, sources) + solve(sources, sinks)) % MOD