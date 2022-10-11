import sys
range = xrange
input = raw_input
 
def fast_modder(MOD):
    """ Returns function modmul(a,b) that quickly calculates a * b % MOD, assuming 0 <= a,b < MOD """
    import sys, platform
    impl = platform.python_implementation()
    maxs = sys.maxsize
    if 'PyPy' in impl and MOD <= maxs and MOD ** 2 > maxs:
        import __pypy__
        intsub = __pypy__.intop.int_sub
        intmul = __pypy__.intop.int_mul
        intmulmod = __pypy__.intop.int_mulmod
        if MOD < 2**30:
            MODINV = 1.0 / MOD
            def modmul(a, b):
                x = intsub(intmul(a,b), intmul(MOD, int(MODINV * a * b)))
                return x - MOD if x >= MOD else (x if x >= 0 else x + MOD)
        else:
            def modmul(a, b):
                return intmulmod(a, b, MOD)
    else:
        def modmul(a, b):
            return a * b % MOD
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
 
    inv_mod = [modmul(fac[i - 1], inv_fac[i]) for i in range(maxN)]
 
    return fac, inv_fac, inv_mod
 
fac, inv_fac, inv_mod = mod_precalc()
 
""" Useful functions involving modulo """
 
def choose(n,k):
    """ Calculate n choose k in O(1) time """
    if k < 0 or k > n:
        return 0
    return modmul(modmul(fac[n], inv_fac[k]), inv_fac[n-k])
 
def redu(x):
    return x if x < MOD else x - MOD
 
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    k = inp[ii]; ii += 1
 
    A = inp[ii : ii + n]; ii += n
    A.sort()
 
    count = 0
 
    j = 0
    for i in range(n):
        while j < n and A[j] - A[i] <= k:
            j += 1
        count = redu(count + choose(j - i - 1, m - 1))
    out.append(count)

print '\n'.join(str(x) for x in out)