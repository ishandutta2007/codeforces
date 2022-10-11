import sys
range = xrange
input = raw_input

class segtree:
    def __init__(self, n):
        self.m = 1
        while self.m < n:
            self.m *= 2

        self.data = [0] * (self.m * 2)

    def __setitem__(self, i, val):
        i += self.m
        self.data[i] = max(self.data[i], val)
        i >>= 1
        while i:
            self.data[i] = max(self.data[2 * i], self.data[2 * i + 1])
            i >>= 1

    def getter(self, l, r):
        l += self.m
        r += self.m
        maxi = 0
        while l < r:
            if l & 1:
                maxi = max(maxi, self.data[l])
                l += 1
            if r & 1:
                r -= 1
                maxi = max(maxi, self.data[r])
            l >>= 1
            r >>= 1
        return maxi


def solve(A, n, m):
    seg = segtree(n + 1)
    B = []
    for i in range(m):
        b = seg[A[i]] = seg.getter(0, A[i] + 1) + 1
        B.append(b)
    for i in range(m - 1):
        B[i + 1] = max(B[i + 1], B[i])
    return B

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1


L = inp[ii + 0: ii + 2 * n: 2]
R = inp[ii + 1: ii + 2 * n: 2]

L = [l - 1 for l in L]

marker = [0] * m
for i in range(n):
    marker[L[i]] += 1
    if R[i] < m:
        marker[R[i]] -= 1

for i in range(m - 1):
    marker[i + 1] += marker[i]

B1 = solve(marker, n, m)
B2 = solve(marker[::-1], n, m)[::-1]

maxi = 0
for i in range(m - 1):
    maxi = max(maxi, B1[i] + B2[i + 1])

print maxi