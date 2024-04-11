import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

marked = [0]*n
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    marked[u] = 1

root = 0
while not marked[root]:
    root += 1

P = [-1]*n
bfs = [root]
P[root] = root
for node in bfs:
    for nei in coupl[node]:
        if P[nei] == -1:
            P[nei] = node
            bfs.append(nei)

for node in reversed(bfs):
    if marked[node]:
        marked[P[node]] = 1

root2 = -1
while not marked[bfs[root2]]:
    root2 -= 1
root2 = bfs[root2]


dist = [-1]*n
dist[root2] = 0
bfs = [root2]
for node in bfs:
    for nei in coupl[node]:
        if dist[nei] == -1:
            dist[nei] = dist[node] + 1
            bfs.append(nei)

diameter = max(dist[i] for i in range(n) if marked[i])

root3 = -1
while not marked[bfs[root3]]:
    root3 -= 1
root3 = bfs[root3]

dist2 = [-1]*n
dist2[root3] = 0
bfs = [root3]
for node in bfs:
    for nei in coupl[node]:
        if dist2[nei] == -1:
            dist2[nei] = dist2[node] + 1
            bfs.append(nei)


i = 0
while not marked[i] or not (dist[i] == diameter or dist2[i] == diameter):
    i += 1

print i + 1
print 2 * sum(marked) - diameter - 2