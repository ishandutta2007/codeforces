import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

n = inp[ii]
ii += 1
m = inp[ii]
ii += 1
q = inp[ii]
ii += 1

A = inp[ii:ii+n]
ii += n

Asum = sum(A[::2]) - sum(A[1::2])

B = inp[ii:ii+m]
ii += m

B = [B[i]*(1 - 2*(i&1)) for i in range(m)]

Bsum = sum(B[:n])
Bvals = [Bsum]
for j in range(1, m - n + 1):
    Bsum -= B[j - 1]
    Bsum += B[j + n - 1]
    Bvals.append(Bsum * (1 - 2*(j&1)))

Bvals.sort()

out = []

def solve():
    a = 0
    b = len(Bvals)
    while 1 + a - b:
        c = a + b >> 1
        if Bvals[c] <= Asum:
            a = c
        else:
            b = c
    if a + 1 < len(Bvals):
        return min(abs(Asum - Bvals[a]), abs(Asum - Bvals[a + 1]))
    return abs(Asum - Bvals[a])

out.append(solve())

for _ in range(q):
    l = inp[ii] - 1
    ii += 1
    r = inp[ii]
    ii += 1

    x = inp[ii]
    ii += 1

    fac = 0
    if l&1:
        fac -= 1
        l += 1
    if (r - l)&1:
        fac += 1
    Asum += fac * x

    out.append(solve())
print '\n'.join(str(x) for x in out)