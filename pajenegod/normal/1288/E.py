import sys
range = xrange
input = raw_input

class segtree:
    def __init__(self, n):
        m = 1
        while m < n: m *= 2
        self.m = m

        self.data = [0]*(2 * m)

    def add(self, l, r, x):
        l += self.m
        r += self.m
        while l < r:
            if l & 1:
                self.data[l] += x
                l += 1
            if r & 1:
                r -= 1
                self.data[r] += x
            l >>= 1
            r >>= 1
    def get(self, i):
        i += self.m
        s = 0
        while i:
            s += self.data[i]
            i >>= 1
        return s

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

A = [a - 1 for a in inp[ii: ii + m]]; ii += m

seg = segtree(n + m)
where = list(range(m, m + n))
for i in range(m, n + m):
    seg.add(i, n + m, 1)

minpos = list(range(1, n + 1))
maxpos = list(range(1, n + 1))

for j in range(m):
    a = A[j]
    pos = seg.get(where[a])
    if pos > maxpos[a]:
        maxpos[a] = pos
    minpos[a] = 1
    
    old = where[a]
    where[a] = m - j - 1
    seg.add(where[a], old, 1)


for i in range(n):
    final = seg.get(where[i])
    if final < minpos[i]:
        minpos[i] = final
    if final > maxpos[i]:
        maxpos[i] = final

print '\n'.join('%d %d' % (minpos[i], maxpos[i]) for i in range(n))