import sys
range = xrange
input = raw_input

class segtree:
    def __init__(self, n):
        self.m = 1
        while self.m < n: self.m *= 2
        self.data = [-1] * (self.m * 2)

    def __setitem__(self, i, val):
        i += self.m
        while i and (self.data[i] > val or self.data[i] == -1):
            self.data[i] = val
            i >>= 1

    def __call__(self):
        i = 1
        goal = self.data[1]
        
        while i < self.m:
            i *= 2
            if self.data[i] != goal:
                i += 1

        j = i >> 1
        self.data[i] = -1
        while j:
            x = self.data[2 * j]
            y = self.data[2 * j + 1]

            a1 = min(x,y)
            a2 = max(x,y)

            self.data[j] = a1 if a1 != -1 else a2
            j >>= 1
        return i - self.m, goal

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

sx,sy,fx,fy = inp[ii: ii + 4]; ii += 4

X = inp[ii + 0: ii + 2 * m: 2]
Y = inp[ii + 1: ii + 2 * m: 2]

N = m + 2
graph = [[] for _ in range(N)]
W = []
V = []

orderX = sorted(range(m), key = X.__getitem__)
orderY = sorted(range(m), key = Y.__getitem__)

for ind in range(m - 1):
    i1 = orderX[ind]
    i2 = orderX[ind + 1]

    w = X[i2] - X[i1]

    eind = len(W)
    W.append(w)
    W.append(w)
    V.append(i2)
    V.append(i1)

    graph[i1].append(eind)
    graph[i2].append(eind + 1)

for ind in range(m - 1):
    i1 = orderY[ind]
    i2 = orderY[ind + 1]

    w = Y[i2] - Y[i1]

    eind = len(W)
    W.append(w)
    W.append(w)
    V.append(i2)
    V.append(i1)

    graph[i1].append(eind)
    graph[i2].append(eind + 1)

for i in range(m):
    w = abs(X[i] - fx) + abs(Y[i] - fy)
    eind = len(W)
    W.append(w)
    V.append(i)
    graph[m].append(eind)

for i in range(m):
    w = min(abs(X[i] - sx), abs(Y[i] - sy))
    eind = len(W)
    W.append(w)
    V.append(m + 1)
    graph[i].append(eind)

# Directly
i1 = m
i2 = m + 1
w = abs(sx - fx) + abs(sy - fy)
eind = len(W)
W.append(w)
V.append(i2)
graph[i1].append(eind)

dist = [-1] * N
seg = segtree(N)
seg[m] = 0
dist[m] = 0

while True:
    i, d = seg()
    if d == -1:
        break 
    for eind in graph[i]:
        v = V[eind]
        w = W[eind]
        if dist[v] == -1 or dist[v] > d + w:
            dist[v] = seg[v] = d + w
print dist[m + 1]