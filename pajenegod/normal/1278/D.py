import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
A = [0]*(2 * n)
L = []
R = []
for i in range(n):
    l = inp[ii] - 1; ii += 1
    r = inp[ii] - 1; ii += 1
    L.append(l)
    R.append(r)
    A[l] = i
    A[r] = ~i


class segtree:
    def __init__(self, n):
        m = 1
        while m < n: m *= 2
        self.m = m
        self.data = [0]*(2 * m)

    def add(self, i):
        i += self.m
        while i:
            self.data[i] += 1
            i >>= 1

    def finder(self, l, r):
        m = self.m
        data = self.data
        l += m
        r += m
        cand = []
        while l < r:
            if l & 1:
                if data[l]:
                    cand.append(l)
                l += 1
            if r & 1:
                r -= 1
                if data[r]:
                    cand.append(r)
            l >>= 1
            r >>= 1
        
        ans = []
        for i in cand:
            while i < m and data[i]:
                if data[2 * i]:
                    cand.append(2 * i)
                i = 2 * i + 1
            if data[i]:
                ans.append(i - m)
        return ans

coupl = [[] for _ in range(n)]
seg = segtree(2 * n)

edges = 0
for j in range(2 * n):
    i = A[j]
    if i >= 0:
        for r_ind in seg.finder(j, R[i]):
            node = ~A[r_ind]
            coupl[i].append(node)
            coupl[node].append(i)
            edges += 1
            if edges == n:
                print 'NO'
                sys.exit()
        seg.add(R[i])

if edges != n - 1:
    print 'NO'
    sys.exit()


found = [0]*n
found[0] = 1
bfs = [0]
for node in bfs:
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = 1
            bfs.append(nei)
if all(found):
    print 'YES'
else:
    print 'NO'