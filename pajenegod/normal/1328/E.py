import sys
range = xrange
input = raw_input

class RangeQuery:
    def __init__(self, data, func=min):
        self.func = func
        self._data = _data = [list(data)]
        i, n = 1, len(_data[0])
        while 2 * i <= n:
            prev = _data[-1]
            _data.append([func(prev[j], prev[j + i]) for j in range(n - 2 * i + 1)])
            i <<= 1

    def __call__(self, begin, end):
        depth = (end - begin).bit_length() - 1
        return self.func(self._data[depth][begin], self._data[depth][end - (1 << depth)])


class LCA:
    def __init__(self, root, graph):
        self.time = [-1] * len(graph)
        self.path = [-1] * len(graph)
        P = [-1] * len(graph)
        t = -1
        dfs = [root]
        while dfs:
            node = dfs.pop()
            self.path[t] = P[node]
            self.time[node] = t = t + 1
            for nei in graph[node]:
                if self.time[nei] == -1:
                    P[nei] = node
                    dfs.append(nei)
        self.rmq = RangeQuery(self.time[node] for node in self.path)

    def __call__(self, a, b):
        if a == b:
            return a
        a = self.time[a]
        b = self.time[b]
        if a > b:
            a, b = b, a
        return self.path[self.rmq(a, b)]

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

depth = [-1]*n
root = 0
depth[root] = 0

bfs = [root]
for node in bfs:
    for nei in coupl[node]:
        if depth[nei] == -1:
            depth[nei] = depth[node] + 1
            bfs.append(nei)

lca = LCA(root, coupl)

out = []
for _ in range(m):
    k = inp[ii]; ii += 1
    A = [node - 1 for node in inp[ii: ii + k]]; ii += k

    bottom = max(A, key = depth.__getitem__)

    if all(depth[node] - depth[lca(node, bottom)] <= 1 for node in A):
        out.append('YES')
    else:
        out.append('NO')
print '\n'.join(out)