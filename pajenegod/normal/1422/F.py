import sys
range = xrange
input = raw_input

# MOD
MOD = 10**9 + 7

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



# GCD
def gcd(a,b):
    while b:
        a, b = b, a % b
    return a

# Prime sieve
big = 2 * 10**5 + 1
marker = [1] * big
primeid = [-1] * big
pid = 0

for i in range(2, big):
    if marker[i] == 1:
        primeid[i] = pid
        pid += 1
        for j in range(i, big, i):
            marker[j] = i

# input and precalc
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii+= 1
A = inp[ii : ii + n]; ii += n

maxsqrt = 1
for i in range(big):
    if i * i < big and marker[i] == i:
        maxsqrt = i

base = [1] * (primeid[maxsqrt] + 1)
# B is to keep track of small prime factors
# C is for large factors
B = []
C = []
for a in A:
    b = list(base)
    c = 1
    while a > 1:
        p = marker[a]
        count = 1
        while a % p == 0:
            a //= p
            count *= p
        if p <= maxsqrt:
            b[primeid[p]] = count
        else:
            c = p
    B.append(b)
    C.append(c)

def merge(A,B):
    return [max(A[i], B[i]) for i in range(len(A))]

### Segtree 1
class brute_seg:
    def __init__(self, A):
        n = len(A)
        data = [base] * (2 * n)
        data[n:n + n] = A
        for i in reversed(range(1, n)):
            data[i] = merge(data[2 * i], data[2 * i + 1])

        def __call__(l,r):
            l += n
            r += n
            B = base
            
            while l < r:
                if l & 1:
                    B = merge(B, data[l])
                    l += 1
                if r & 1:
                    r -= 1
                    B = merge(B, data[r])
                l >>= 1
                r >>= 1
            ans = 1
            for b in B:
                ans = modmul(ans, b)
            return ans
        self.__call__ = __call__

smallseg = brute_seg(B)

### Segtree 2

from bisect import bisect_left as binsearch
class mod_mergesort_seg:
    def __init__(self, A, B):
        n = len(A)
        
        data = [[]] * (2 * n)
        data[n:2 * n] = [[a] for a in A]

        for i in reversed(range(1, n)):
            data[i] = sorted(data[2 * i] + data[2 * i + 1])
        
        cumsummer = [[1]] * (2 * n)
        for i in range(1, 2 * n):
            C = [1]
            cumsummer[i] = C
            for d in data[i]:
                C.append(modmul(C[-1], B[d]))

        def query(l, r, x):
            """ Count number of i in [l,r) such that A[i] < x """
            l += n
            r += n
            ans = 1
            while l < r:
                if l & 1:
                    ans = modmul(ans, cumsummer[l][binsearch(data[l], x)])
                    l += 1
                if r & 1:
                    r -= 1
                    ans = modmul(ans, cumsummer[r][binsearch(data[r], x)])
                l >>= 1
                r >>= 1
            return ans
        self.query = query

class unique_seg:
    def __init__(self, A):
        n = len(A)

        I = []
        seen = {}
        for i in range(n):
            a = A[i]
            I.append(seen[a] if a in seen else i - n)
            seen[a] = i
        
        seg = mod_mergesort_seg(I, A)
        self.__call__ = lambda l, r: seg.query(l, r, l)

largeseg = unique_seg(C)

### Queries

q = inp[ii]; ii += 1
L = inp[ii + 0: ii + 2 * q: 2]
R = inp[ii + 1: ii + 2 * q: 2]
ii += 2 * q

ans = []
last = 0
for qind in range(q):
    l = (last + L[qind]) % n
    r = (last + R[qind]) % n
    if l > r:
        l,r = r,l
    r += 1

    #val = 1
    #for a in A[l:r]:
    #    val = val * a // gcd(val, a)
    #last = val

    last = modmul(smallseg(l,r), largeseg(l,r))

    ans.append(last)
print '\n'.join(str(x) for x in ans)