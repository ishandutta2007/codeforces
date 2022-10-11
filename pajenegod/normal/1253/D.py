import sys
range = xrange
input = raw_input

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

dsu = DisjointSetUnion(n)

for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    dsu.union(u,v)

comp = [[] for _ in range(n)]
for i in range(n):
    comp[dsu.find(i)].append(i)

found = 0
maxfound = -1
count1 = 0
count2 = 0
for i in range(n):
    if comp[i]:
        count1 += 1
        for j in comp[i]:
            if j > maxfound:
                maxfound = j
            found += 1

        if found - 1 == maxfound:
            count2 += 1

print count1 - 1 - (count2 - 1)