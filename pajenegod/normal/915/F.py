import sys
range = xrange
input = raw_input

# returns order such that A[order[i]] <= A[order[i + 1]]
def sqrtsorted(A, maxval = 10**6):
    mask = 2**10 - 1
    blocks1 = [[] for _ in range(mask + 1)]
    blocks2 = [[] for _ in range(mask + 1)]
    for i in range(len(A)):
        blocks1[A[i] & mask].append(i)
    for block in blocks1:
        for i in block:
            blocks2[A[i] >> 10].append(i)
    ret = []
    for block in blocks2:
        ret += block
    return ret


class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def join(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a
            self.parent[b] = a
            self.size[a] += self.size[b]
        return (self.size[a] - self.size[b]) * (self.size[b])

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
A = inp[ii:ii + n]; ii += n

order = sqrtsorted(A)
mapper = [0]*n
for i in range(n):
    mapper[order[i]] = i
B = [A[i] for i in order]

coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = mapper[inp[ii] - 1]; ii += 1
    v = mapper[inp[ii] - 1]; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

total = 0

dsu = DisjointSetUnion(n)
for node in range(n):
    s = 0
    for nei in coupl[node]:
        if nei < node:
            s += dsu.join(node, nei)
    total += s * B[node]

dsu = DisjointSetUnion(n)
for node in reversed(range(n)):
    s = 0
    for nei in coupl[node]:
        if nei > node:
            s += dsu.join(node, nei)
    total -= s * B[node]

print total