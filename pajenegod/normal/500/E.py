import sys
range = xrange
input = raw_input

class segtree:
    def __init__(s, data, f):
        s.n = len(data)
        s.m = 1
        s.f = f
        while s.m < s.n:
            s.m *= 2
        s.data = [0]*(2 * s.m)
        s.data[s.m: s.m + s.n] = data
        for i in reversed(range(1, s.m)):
            s.data[i] = f(s.data[2 * i], s.data[2 * i + 1])
    def set(s, i, x):
        i += s.m
        while i:
            s.data[i] = x
            x = s.f(x, s.data[i ^ 1])
            i >>= 1
    def query(s, l, r):
        l += s.m
        r += s.m
        x = s.data[l]
        while l<r:
            if l & 1:
                x = s.f(x, s.data[l])
                l += 1
            if r & 1:
                x = s.f(x, s.data[r - 1])
            l >>= 1
            r >>= 1
        return x

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

n = inp[ii]
ii += 1

L = inp[ii:ii + 2*n:2]
lens = inp[ii + 1:ii + 2*n:2]
ii += 2*n
R = [L[i] + lens[i] + 1 for i in range(n)]
Rseg = segtree(R, max)

DP = [0]*n
DPseg = segtree(DP, min)
for i in reversed(range(n - 1)):
    if R[i] <= L[i + 1]:
        DP[i] = L[i + 1] - R[i] + 1 + DP[i + 1]
    else:
        a = i + 1
        b = n - 1
        r = R[i]
        while a < b:
            c = a + b + 1 >> 1
            if L[c] < r:
                a = c
            else:
                b = c - 1
        DP[i] = DPseg.query(i + 1, a + 1)
        if a + 1 < n:
            DP[i] = min(DP[i], L[a + 1] - r + 1 + DP[a + 1])
    DPseg.set(i, DP[i])

q = inp[ii]
ii += 1

out = []
for _ in range(q):
    x = inp[ii] - 1
    ii += 1
    y = inp[ii]
    ii += 1

    cost = DP[x]
    r = Rseg.query(x,y)
        
    a = y - 1
    b = n - 1
    while a < b:
        c = a + b + 1 >> 1
        if L[c] < r:
            a = c
        else:
            b = c - 1
    cost -= DPseg.query(x, a + 1)
    out.append(cost)

print '\n'.join(str(x) for x in out)