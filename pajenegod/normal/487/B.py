import sys
range = xrange
input = raw_input

class segtree:
    def __init__(self, data, f):
        self.f = f
        n = len(data)
        self.m = 1
        while self.m < n: self.m *= 2

        self.data = [0]*(2 * self.m)
        self.data[self.m: self.m + n] = data
        for i in reversed(range(1, self.m)):
            self.data[i] = f(self.data[2 * i], self.data[2 * i + 1])

    def __setitem__(self, i, val):
        i += self.m
        self.data[i] = val
        i >>= 1
        while i:
            self.data[i] = self.f(self.data[2 * i], self.data[2 * i + 1])
            i >>= 1

    def __getitem__(self, i):
        return self(i, i + 1)

    def __call__(self, l, r):
        l += self.m
        r += self.m
        val = self.data[l]
        while l < r:
            if l & 1:
                val = self.f(val, self.data[l])
                l += 1
            if r & 1:
                r -= 1
                val = self.f(val, self.data[r])
            l >>= 1
            r >>= 1
        return val

n,s,l = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

maxseg = segtree(A, max)
minseg = segtree(A, min)

inf = 10**6
dp = [inf] * n + [0]
dpseg = segtree(dp, min)

# dp[i] = minimal number of strips using A[i:n]

r = n
for i in reversed(range(n)):
    # r is largest r such that max(A[i:r]) - min(A[i:r]) <= s
    while maxseg(i, r) - minseg(i, r) > s:
        r -= 1
    if i + l <= r:
        dpseg[i] = dpseg(i + l, r + 1) + 1
ans = dpseg[0]
print ans if ans < inf else -1