import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

coupl = [[] for _ in range(n)]
U = []

for eind in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1

    coupl[u].append(2*eind)
    coupl[v].append(2*eind + 1)

    U.append(u)
    U.append(v)

root = 0
bfs = [root]
P = [-1]*n
for node in bfs:
    for eind in coupl[node]:
        nei = U[eind ^ 1]
        P[nei] = eind ^ 1
        coupl[nei].remove(eind ^ 1)
        bfs.append(nei)

order = [0]*n
for i in range(n):
    order[bfs[i]] = i

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n
        self.true = list(range(n))

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def merge(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]
            if order[self.true[b]] < order[self.true[a]]:
                self.true[a] = self.true[b]

dsu = DisjointSetUnion(n)

m = inp[ii]; ii += 1
paths = []
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    w = inp[ii]; ii += 1
    paths.append((w,u,v))

F = [1]*(n - 1)

paths.sort()

while paths:
    w = paths[-1][0]
    tmp = []
    while paths and paths[-1][0] == w:
        w,u,v = paths.pop()
        
        u = dsu.true[dsu.find(u)]
        v = dsu.true[dsu.find(v)]
        
        if u == v:
            print -1
            sys.exit()
        
        tmp.append((u,v))
    
    for u,v in tmp:
        u = dsu.true[dsu.find(u)]
        v = dsu.true[dsu.find(v)]
        
        while u != v:
            if order[u] < order[v]:
                eind = P[v]
                F[eind >> 1] = w
                dsu.merge(v, U[eind ^ 1])

                v = dsu.true[dsu.find(v)]
            else:
                eind = P[u]
                F[eind >> 1] = w
                dsu.merge(u, U[eind ^ 1])
                
                u = dsu.true[dsu.find(u)]
print ' '.join(str(f) for f in F)