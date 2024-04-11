import sys
range = xrange
input = raw_input

## LCA
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
        self.path = []
        dfs = [root]
        while dfs:
            node = dfs.pop()
            self.path.append(node)
            if self.time[node] == -1:
                self.time[node] = len(self.path) - 1
                for nei in graph[node]:
                    if self.time[nei] == -1:
                        dfs.append(node)
                        dfs.append(nei)
        self.rmq = RangeQuery(self.time[node] for node in self.path)
 
    def __call__(self, a, b):
        a = self.time[a]
        b = self.time[b]
        if a > b:
            a, b = b, a
        return self.path[self.rmq(a, b + 1)]
## END LCA


class Binary_lifting:
    def __init__(self, graph, data, f):
        n = len(graph)
        LG = 1
        while LG * 2**LG < n: LG += 1

        depth = [-1]*n
        occ = [0]*LG
        root = 0
        bfs = [root]
        depth[root] = 0
        P = [root]*n
        for node in bfs:
            for nei in graph[node]:
                if depth[nei] == -1:
                    bfs.append(nei)
                    P[nei] = node
                    h = depth[nei] = depth[node] + 1
                    occ[h % LG] += 1
        
        minfrec = (-min(range(LG), key = occ.__getitem__)) % LG
        depth = [h + minfrec for h in depth]

        jump0     = list(range(n))
        jump0_val = [0]*n
        small_jump     = [[] for _ in range(n)]
        small_jump_val = [[] for _ in range(n)]
        big_jump     = [[] for _ in range(n)]
        big_jump_val = [[] for _ in range(n)]

        small_jump[root] = [root]*LG
        small_jump_val[root] = [data[root]]*LG
        big_jump[root] = [root]*LG
        big_jump_val[root] = [data[root]]*LG

        for node in bfs:
            h = depth[node]
            if h % LG == 0:
                tmp = small_jump[node]
                tmp_val = small_jump_val[node]

                tmp.append(node)
                tmp_val.append(0)

                val = data[node]
                a = P[node]
                while len(tmp) < LG:
                    tmp.append(a)
                    tmp_val.append(val)
                    val = f(val, data[a])
                    a = P[a]

                big_jump[node].append(a)
                big_jump_val[node].append(val)
                for i in range(LG - 1):
                    val = f(val, big_jump_val[a][i])
                    a = big_jump[a][i]
                    big_jump[node].append(a)
                    big_jump_val[node].append(val)
            elif h % LG == 1 or node == root:
                jump0[node] = P[node]
                jump0_val[node] = data[node]
            else:
                jump0[node] = jump0[P[node]]
                jump0_val[node] = f(data[node], jump0_val[P[node]])

        self.data = data
        self.f = f
        self.lca = LCA(root, graph)
        self.LG = LG
        self.P = P
        self.depth = depth
        self.jump0     = jump0
        self.jump0_val = jump0_val
        self.small_jump     = small_jump
        self.small_jump_val = small_jump_val
        self.big_jump     = big_jump
        self.big_jump_val = big_jump_val

    def __call__(self, u, v):
        w = self.lca(u,v)
        goal = self.depth[w]
        goalmod = (-goal) % self.LG

        val = self.data[w]

        for node in u,v:
            h = self.depth[node]
            h0 = h - (h % self.LG)
            if goal > h0:
                for _ in range(h - goal):
                    val = self.f(val, self.data[node])
                    node = self.P[node]
            else:
                if h0 != h:
                    val = self.f(val, self.jump0_val[node])
                    node = self.jump0[node]
                d = (h0 - goal) // self.LG
                while d:
                    i = d.bit_length() - 1
                    val = self.f(val, self.big_jump_val[node][i])
                    node = self.big_jump[node][i]
                    d -= 1 << i
                if goalmod:
                    val = self.f(val, self.small_jump_val[node][goalmod])
                    node = self.small_jump[node][goalmod]
        return val

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
q = inp[ii]; ii += 1
 
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
 
    coupl[u].append(v)
    coupl[v].append(u)
 
def f(A, B):
    ans = []
    A = list(A)
    B = list(B)
    goal = min(10, len(A) + len(B))
    while len(ans) < goal:
        if A and (not B or A[-1] < B[-1]):
            ans.append(A.pop())
        else:
            ans.append(B.pop())
    ans.reverse()
    return ans
 
C = inp[ii:ii + m]; ii += m
data = [[] for _ in range(n)]
for i in range(m):
    if len(data[C[i] - 1]) < 10:
        data[C[i] - 1].append(i + 1)
for d in data:
    d.reverse()
BL = Binary_lifting(coupl, data, f)
 
out = []
for _ in range(q):
    v = inp[ii] - 1; ii += 1
    u = inp[ii] - 1; ii += 1
    a = inp[ii]; ii += 1
 
    ans = list(BL(v, u))
    ans.append(min(len(ans), a))
    out.append(' '.join(str(x) for x in ans[-1:~a-1:-1]))
print '\n'.join(out)