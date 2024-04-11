import sys
from collections import defaultdict
range = xrange
input = raw_input

class segtree:
    def __init__(self, n):
        m = 1
        while m < n: m *= 2
        self.m = m
        self.data1 = [0.0]*(m + m)
        self.data2 = [0]*(m + m)

    def add(self, i, val):
        i += self.m
        while i:
            self.data1[i] += val
            self.data2[i] += 1
            i >>= 1

    def summer(self, l, r):
        l += self.m
        r += self.m
        s1 = 0.0
        s2 = 0
        while l < r:
            if l & 1:
                s1 += self.data1[l]
                s2 += self.data2[l]
                l += 1
            if r & 1:
                r -= 1
                s1 += self.data1[r]
                s2 += self.data2[r]
            l >>= 1
            r >>= 1
        return s1,s2

jj = -1
def map_fun():
    global jj
    jj += 1
    return jj

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
X = inp[ii: ii + n]; ii += n
V = inp[ii: ii + n]; ii += n

order = sorted(range(n), key = lambda i: (V[i], X[i]))

mapper = defaultdict(map_fun)
for x in sorted(X):
    mapper[x]

seg = segtree(len(mapper))
total = 0
for i in order:
    x = X[i]
    j = mapper[x]

    s1, s2 = seg.summer(0,j)
    total += int(s2 * x - s1)
    seg.add(j, x)

print int(total)