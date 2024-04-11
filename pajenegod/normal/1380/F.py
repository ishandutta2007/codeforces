import sys
range = xrange
input = raw_input

class segtree:
    def __init__(self,n):
        self.m = 1
        while self.m < n:
            self.m *= 2
        self.data = [0] * (2 * self.m)

    def __setitem__(self,i,x):
        x = +(x != 1)
        i += self.m
        self.data[i] = x
        i >>= 1
        while i:
            self.data[i] = self.data[2 * i] + self.data[2 * i + 1]
            i >>= 1

    def __call__(self,l,r):
        l += self.m
        r += self.m
        s = 0
        while l < r:
            if l & 1:
                s += self.data[l]
                l += 1
            if r & 1:
                r -= 1
                s += self.data[r]
            l >>= 1
            r >>= 1
        return s


MOD = 998244353 

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

modmul = fast_modder(MOD)
class mod_handle:
    def __init__(self):
        self.stored = 0
    def __rpow__(self, x):
        self.stored = x
        return self
    def __rmul__(self, x):
        return modmul(x, self.stored)
    def __rsub__(self, x):
        return x if x < MOD else x - MOD
    def __radd__(self, x):
        return x + MOD if x < 0 else x

modder = mod_handle()
def modinv(x):
    return pow(x, MOD - 2, MOD)


n,m = [int(x) for x in input().split()]
C = [ord(c) - ord('0') for c in input()]

seg = segtree(n)
for i in range(n):
    seg[i] = C[i]

def valer(n, x):
    if n == -1:
        return 1
    if n == 0:
        return x + 1
    return DP[n] * (x + 1) ** modder + DP[n - 1] * (9 - x) ** modder - modder

DP = [1] * (n + 1)
for i in range(1, n + 1):
    DP[i] = valer(i - 1, 1)

ways = 1
i = 0
while i < len(C):
    j = i
    while j + 1 < len(C) and C[j] == 1:
        j += 1
    ways *= valer(j - i, C[j]) ** modder
    i = j + 1

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

out = []

for _ in range(m):
    a = inp[ii] - 1; ii += 1
    x = inp[ii]; ii += 1

    if C[a] == x:
        out.append(ways)
        continue

    aa = -1
    bb = a - 1
    while aa < bb:
        cc = aa + bb + 1 >> 1
        if seg(cc, a) > 0:
            aa = cc
        else:
            bb = cc - 1
    before = aa
    
    aa = a + 1
    bb = n
    while aa < bb:
        cc = aa + bb >> 1
        if seg(a + 1, cc + 1) > 0:
            bb = cc
        else:
            aa = cc + 1
    after = aa

#    before = a - 1
#    while before >= 0 and C[before] == 1:
#        before -= 1
    
#    after = a + 1
#    while after < n and C[after] == 1:
#        after += 1

    oneL = a - before - 1
    oneR = after - a - 1

    if C[a] == 1:
        if after < n:
            ways *= modinv(valer(oneL + oneR + 1, C[after])) ** modder

            seg[a] = C[a] = x
            ways *= valer(oneL, x) ** modder
            ways *= valer(oneR, C[after]) ** modder
        else:
            ways *= modinv(valer(oneL + oneR, 1)) ** modder
            
            seg[a] = C[a] = x
            ways *= valer(oneL, x) ** modder
            ways *= valer(oneR - 1, 1) ** modder
                

    else:
        if x == 1:
            if after < n:
                ways *= modinv(valer(oneL, C[a]) * valer(oneR, C[after]) ** modder) ** modder
                seg[a] = C[a] = x
                ways *= valer(oneL + oneR + 1, C[after]) ** modder
            else:
                ways *= modinv(valer(oneL, C[a]) * valer(oneR - 1, 1) ** modder) ** modder
                seg[a] = C[a] = x
                ways *= valer(oneL + oneR, 1) ** modder
        else:
            ways *= modinv(valer(a - before - 1, C[a])) ** modder
            seg[a] = C[a] = x
            ways *= valer(a - before - 1, C[a]) ** modder
    out.append(ways)

print '\n'.join(str(x) for x in out)