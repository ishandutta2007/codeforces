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

n,k = [int(x) for x in input().split()]

for i in range(k + 1):
    print '?',' '.join(str(j + 1) for j in range(k + 1) if j != i)

A = [-1]*n

Q = []
for _ in range(k + 1):
    pos, a = [int(x) for x in input().split()]
    Q.append((pos - 1, a))
    A[pos - 1] = a

med = Q[-1][0]

smaller = []
larger = []

for i in [i for i in range(k) if i != med]:
    pos, a = Q[i]
    if a == A[med]:
        smaller.append(i)
    else:
        larger.append(i)

if Q[med][1] > A[med]:
    smaller,larger = larger,smaller

print '!', len(smaller) + 1