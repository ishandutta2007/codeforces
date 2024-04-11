import io
import os
import sys

# Trying to speed up c1729, which in turn is trying to speed up pajenegod's submissions
# which in turn is trying to speed up meooows code

a = os.read(0, os.fstat(0).st_size)
# Speed
inp = []
i = 0
numb = 0
try:
    while True:
        if a[i] >= b'0' [0]:
            numb = 10 * numb + a[i] - 48
        elif a[i] != b'\r' [0]:
            inp.append(numb)
            numb = 0
        i += 1
except:
    pass
if a and a[-1] >= b'0' [0]:
    inp.append(numb)
ii = 0

# Homemade stable mergesort
def mergesort(A, gt_cmp=None):
    if gt_cmp is None:
        gt_cmp = lambda i,j: i>j

    B, n = A[:], len(A)
    for i in range(0,n-1,2):
        if gt_cmp(A[i],A[i^1]):
            A[i],A[i^1] = A[i^1],A[i]
    width = 2
    while width < n:
        for i in range(0,n, 2*width):
            R1 = j = min(i + width, n) 
            R2 = min(i + 2 * width, n)
            k = i
            while i<R1 and j<R2:
                if gt_cmp(A[i],A[j]):
                    B[k] = A[j]
                    j += 1
                else:
                    B[k] = A[i]
                    i += 1
                k += 1
            while i<R1:
                B[k] = A[i]
                k += 1
                i += 1
            while k<R2:
                B[k] = A[k]
                k += 1
        A,B = B,A
        width *= 2
    return A




# Using pajenegod's floating point mod mul

MOD = 998244353
MODF = float(MOD)

MAGIC = 6755399441055744.0
SHRT = 65536.0

MODF_INV = 1.0 / MODF
SHRT_INV = 1.0 / SHRT

fround = lambda x: (x + MAGIC) - MAGIC
fmod = lambda a: a - MODF * fround(MODF_INV * a)
fmul = lambda a, b, c=0.0: fmod(fmod(a * SHRT) * fround(SHRT_INV * b) + a * (b - SHRT * fround(b * SHRT_INV)) + c)


def fpow(x, y):
    if y == 0:
        return 1.0

    res = 1.0
    while y > 1:
        if y & 1 == 1:
            res = fmul(res, x)
        x = fmul(x, x)
        y >>= 1

    return fmul(res, x)


n, m = inp[ii], inp[ii + 1]
ii += 2

a = inp[ii:ii + n * m]
ii += n * m

# try this against vanilla sort
order = mergesort(list(range(n*m)), lambda i,j:a[i]>a[j])

sx, sy = inp[ii], inp[ii + 1]
ii += 2

MX = n * m + 1
inv = [0.0] * MX
inv[1] = 1.0
for i in range(2, MX):
    inv[i] = fmul(-1.0 * (MOD // i), inv[MOD % i])

fsum = isum = i2sum = jsum = j2sum = 0
cnt = 0
inv_cnt = 0.0
i = 0
fa = [0] * (n * m)
while i < n * m:
    j = i + 1
    while j < n * m and a[order[i]] == a[order[j]]:
        j += 1
    for k in range(i, j):
        x, y = divmod(order[k], m)
        x += 1
        y += 1

        f = fmul(1.0 * cnt, 1.0 * (x * x + y * y), i2sum + j2sum + fsum - 2.0 * (x * isum + y * jsum))
        f = fmul(f, inv_cnt)
        if sx == x and sy == y:
            print(int(f + MODF) % MOD)
            sys.exit()
        fa[k] = int(f)
    for k in range(i, j):
        x, y = divmod(order[k], m)
        x += 1.0
        y += 1.0
        fsum = (fa[k] + fsum) % MOD
        isum += x
        i2sum += x * x
        jsum += y
        j2sum += y * y
    cnt += j - i
    inv_cnt = inv[cnt]
    i = j