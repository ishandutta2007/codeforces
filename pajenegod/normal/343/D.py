import sys
input = raw_input
 
class segtree:
    def __init__(self, n):
        m = 1
        while m < n:
            m *= 2
        self.n = m
        self.data = [0] * (2 * m)
        self.history = [0]
 
    def query(self, l, r, x):
        ver_id = len(self.history)
        self.history.append(x)
        
        l += self.n
        r += self.n
        x = 0
        while l < r:
            if l & 1:
                self.data[l] = ver_id
                l += 1
            if r & 1:
                r -= 1
                self.data[r] = ver_id
            l //= 2
            r //= 2
    
    def __getitem__(self, ind):
        ind += self.n
        ver_id = 0
        while ind:
            ver_id = max(self.data[ind], ver_id)
            ind >>= 1
        return self.history[ver_id]
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
 
graph = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    graph[u].append(v)
    graph[v].append(u)
 
bfs = [0]
P = [-1] * n
for node in bfs:
    for nei in graph[node]:
        graph[nei].remove(node)
        P[nei] = node
    bfs += graph[node]
 
subtree_size = [1] * n
for node in reversed(bfs):
    subtree_size[node] += sum(subtree_size[child] for child in graph[node])
 
preorder = []
dfs = [0]
while dfs:
    node = dfs.pop()
    preorder.append(node)
    dfs += sorted(graph[node], key = subtree_size.__getitem__)
 
where = [0] * n
for i in range(n):
    where[preorder[i]] = i
 
heavy_root = [-1] * n
for node in bfs:
    p = P[node]
    if where[p] == where[node] - 1:
        heavy_root[node] = heavy_root[p]
    else:
        heavy_root[node] = node
 
seg = segtree(n)
q = inp[ii]; ii += 1
out = []
for _ in range(q):
    c = inp[ii]; ii += 1
    node = inp[ii] - 1; ii += 1
    if c == 1:
        ind = where[node]
        seg.query(ind, ind + subtree_size[node], 1)
    elif c == 2:
        while node != -1:
            hp = heavy_root[node]
            seg.query(where[hp], where[node] + 1, 0)
            node = P[hp]
    else: # c == 3
        out.append(seg[where[node]])
 
print '\n'.join(str(x) for x in out)