import os
from io import BytesIO

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

MOD = 998244353
ROOT = 3.0
MODF = 1.0*MOD
MODF_inv = 1.0/MODF
SHRT = float(1 << 16)
SHRT_inv = 1.0/SHRT
MAGIC = float(2**52+2**51)
ffloor = lambda x:(x+MAGIC)-MAGIC
modder = lambda a:a - MODF * ffloor(MODF_inv*a)
mod_prod = lambda a, b:\
    modder(modder(a * SHRT) * ffloor(SHRT_inv*b) + a*(b-SHRT * ffloor(b*SHRT_inv)))

def fpow(x, y):
    res = 1.0
    if y==0:return x
    while y > 1:
        if y & 1:
            res = mod_prod(res, x)
        x = mod_prod(x, x)
        y >>= 1
    return mod_prod(res, x)

def mod_sq(x):
    return mod_prod(x,x)

def ntt(a, inv=False):
    n = len(a)
    w = [1.0] * (n >> 1)

    w[1] = fpow(ROOT, (MOD - 1) // n)
    if inv:
        w[1] = fpow(w[1], MOD - 2)

    for i in xrange(2, (n >> 1)):
        w[i] = mod_prod(w[i - 1], w[1])

    rev = [0] * n
    for i in xrange(n):
        rev[i] = rev[i >> 1] >> 1
        if i & 1 == 1:
            rev[i] |= (n >> 1)
        if i < rev[i]:
            a[i], a[rev[i]] = a[rev[i]], a[i]

    step = 2
    while step <= n:
        half, diff = step >> 1, n / step
        for i in xrange(0, n, step):
            pw = 0
            for j in xrange(i, i + half):
                v = mod_prod(w[pw],a[j + half])
                a[j + half] = a[j] - v
                a[j] += v
                pw += diff

        step <<= 1

    if inv:
        inv_n = fpow(n, MOD - 2)
        for i in xrange(n):
            a[i] = mod_prod(a[i], inv_n)


def conv(a, b):
    s = len(a) + len(b) - 1
    n = 1 << s.bit_length()

    a.extend([0.0] * (n - len(a)))
    b.extend([0.0] * (n - len(b)))

    ntt(a)
    ntt(b)

    for i in xrange(n):
        a[i] = mod_prod(a[i], b[i])

    ntt(a, inv=True)
    del a[s:]


def main():
    N, _ = input().split()
    n = int(N) >> 1
    
    big = (1+9*(n+1))
    m = 1
    while m<big:m*=2

    d = [0.0] * m
    for i in input().split():
        d[int(i)] = 1.0

    ntt(d)
    d = [fpow(i,n) for i in d]
    ntt(d,inv=True)
    d = [mod_sq(i) for i in d]
    print(int(sum(d))%MOD)

if __name__ == '__main__':
    main()