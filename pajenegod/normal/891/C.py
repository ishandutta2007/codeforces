import sys, collections
range = xrange
input = raw_input

class DisjointSetUnion0:
    def __init__(self, n):
        self.data = [-1] * n

    def __getitem__(self, a):
        acopy = a
        while self.data[a] >= 0:
            a = self.data[a]
        while acopy != a:
            self.data[acopy], acopy = a, self.data[acopy]
        return a

    def __call__(self, a, b):
        a, b = self[a], self[b]
        if a != b:
            if self.data[a] > self.data[b]:
                a, b = b, a

            self.data[a] += self.data[b]
            self.data[b] = a
            return True
        return False

class DisjointSetUnion1(DisjointSetUnion0):
    def __init__(self):
        self.data = collections.defaultdict(lambda: -1)

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

V = []
W = []
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    w = inp[ii]; ii += 1
    eind = len(V)
    V.append(v)
    V.append(u)
    W.append(w)

q = inp[ii]; ii += 1
ans = [1]*q

queries = collections.defaultdict(list)

for qind in range(q):
    k = inp[ii]; ii += 1
    E = [eind - 1 << 1 for eind in inp[ii: ii + k]]; ii += k
    found = set()
    for eind in E:
        w = W[eind >> 1]
        if w not in found:
            found.add(w)
            queries[w].append([qind])
        queries[w][-1].append(eind)

buckets = collections.defaultdict(list)
for eind in range(0, 2 * m, 2):
    buckets[W[eind >> 1]].append(eind)

dsu0 = DisjointSetUnion0(n)
for w in sorted(buckets):
    for query in queries[w]:
        dsu1 = DisjointSetUnion1()
        qind = query[0]
        for eind in query[1:]:
            v = dsu0[V[eind]]
            u = dsu0[V[eind ^ 1]]
            if not dsu1(u,v):
                ans[qind] = 0
                break

    for eind in buckets[w]:
        dsu0(V[eind], V[eind ^ 1])

print '\n'.join('YES' if a else 'NO' for a in ans)