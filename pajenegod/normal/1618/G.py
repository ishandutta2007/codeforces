import sys

class DisjointSetUnion:
    def __init__(self, Acount):
        n = len(Acount)
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n
        self.Acount = list(Acount)
        self.R = list(range(n))

        s = 0
        for i in range(n):
            if Acount[i]:
                s += ABsorted[i]
        self.s = s

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

            s = 0

            r = self.R[a] + 1
            l = r - self.Acount[a]
            s -= cumsum[r] - cumsum[l]

            r = self.R[b] + 1
            l = r - self.Acount[b]
            s -= cumsum[r] - cumsum[l]

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]
            self.R[a] = max(self.R[a], self.R[b])
            self.Acount[a] += self.Acount[b]
            
            r = self.R[a] + 1
            l = r - self.Acount[a]
            s += cumsum[r] - cumsum[l]

            self.s += s


inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
q = inp[ii]; ii += 1

A = inp[ii:ii + n]; ii += n
B = inp[ii:ii + m]; ii += m

AB = A + B
order = sorted(range(n + m), key = AB.__getitem__)

ABsorted = sorted(AB)

cumsum = [0]
for val in ABsorted:
    cumsum.append(cumsum[-1] + val)

DSU = DisjointSetUnion([+(i < n) for i in order])


diffAB = [ABsorted[i] - ABsorted[i - 1] for i in range(1, len(AB))]
diffABorder = sorted(range(len(diffAB)), key = diffAB.__getitem__, reverse = True)

Q = inp[ii:ii + q]; ii += q
ans = [-1] * q
Qorder = sorted(range(q), key = Q.__getitem__)

for qind in Qorder:
    k = Q[qind]
    while diffABorder and diffAB[diffABorder[-1]] <= k:
        i = diffABorder.pop()

        DSU.merge(i, i + 1)

    ans[qind] = DSU.s

print('\n'.join(str(x) for x in ans))