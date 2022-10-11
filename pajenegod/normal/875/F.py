import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

A = inp[ii + 0: ii + 3 * m: 3]
B = inp[ii + 1: ii + 3 * m: 3]
W = inp[ii + 2: ii + 3 * m: 3]

A = [a - 1 for a in A]
B = [b - 1 for b in B]

order = sorted(range(m), key = W.__getitem__, reverse = True)

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.state = [0] * n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def join(self, a, b, w):
        a, b = self.find(a), self.find(b)
        sa = self.state[a]
        sb = self.state[b]
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a

            self.parent[b] = a
            self.size[a] += self.size[b]
            self.state[a] |= self.state[b]

            if not sa == sb == 1:
                return w
        else:
            if sa == 0:
                self.state[a] = 1
                return w
        return 0

dsu = DisjointSetUnion(n)
total = 0
for i in order:
    total += dsu.join(A[i], B[i], W[i])
print total