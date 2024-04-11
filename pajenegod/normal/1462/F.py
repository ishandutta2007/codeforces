import sys
range = xrange
input = raw_input

class segtree:
    def __init__(self, n):
        self.data = data = [0] * (2 * n)

        def setter(i, x):
            i += n
            while i:
                data[i] += x
                i >>= 1
        self.setter = setter

        def getter(l,r):
            l += n
            r += n
            s = 0
            while l < r:
                if l & 1:
                    s += data[l]
                    l += 1
                if r & 1:
                    r -= 1
                    s += data[r]
                l >>= 1
                r >>= 1
            return s
        self.getter = getter


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1

    L = inp[ii + 0: ii + 2 * n: 2]
    R = inp[ii + 1: ii + 2 * n: 2]
    ii += 2 * n

    mapper = {}
    for x in sorted(L + R):
        if x not in mapper:
            mapper[x] = len(mapper)
    m = len(mapper)

    L = [mapper[x] for x in L]
    R = [mapper[x] for x in R]

    Lbuckets = [[] for _ in range(m)]
    Rbuckets = [[] for _ in range(m)]
    for i in range(n):
        Lbuckets[L[i]].append(i)
        Rbuckets[R[i]].append(i)

    seg = segtree(m + 1)

    besta = 0
    for x in range(m):
        for i in Lbuckets[x]:
            seg.setter(R[i], 1)
        
        for i in Rbuckets[x]:
            besta = max(besta, seg.getter(L[i], m + 1))

    out.append(n - besta)

print '\n'.join(str(x) for x in out)