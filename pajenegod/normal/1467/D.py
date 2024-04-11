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
            def modmul(a, b, c = 0):
                x = intsub(intmul(a,b), intmul(MOD, int(MODINV * a * b)))
                return (x + c) % MOD
        else:
            def modmul(a, b):
                return intmulmod(a, b, MOD)
    else:
        def modmul(a, b):
            return a * b % MOD
    return modmul


""" Precalculate factorial, modular inverse of factorial and modular inverse """
MOD = 10 ** 9 + 7 # needs to be prime!
modmul = fast_modder(MOD)

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

n = inp[ii]; ii += 1
k = inp[ii]; ii += 1

DP = [[1] * (n + 1)]
DP[0][-1] = 0

for i in range(k):
    prev = DP[-1]
    nesta = [(prev[i - 1] + prev[i + 1]) % MOD for i in range(n)]
    nesta.append(0)
    DP.append(nesta)

count = [0] * n
for j in range(k + 1):
    DPj = DP[j]
    DPmj = DP[~j]
    
    for i in range(n):
        count[i] = modmul(DPj[i], DPmj[i], count[i])


q = inp[ii]; ii += 1
A = inp[ii: ii + n]; ii += n
QI = inp[ii + 0: ii + 2 * q: 2]
QX = inp[ii + 1: ii + 2 * q: 2]
ii += 2 * q

total = 0
for i in range(n):
    total = modmul(count[i], A[i], total)

for qind in range(q):
    i = QI[qind] - 1
    x = QX[qind]

    total = modmul(count[i], (x - A[i]), total)
    A[i] = x
    out.append(total)
print '\n'.join(str(x) for x in out)