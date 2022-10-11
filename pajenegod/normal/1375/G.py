import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

root = 0
bfs = [root]
depth = [-1] * n
depth[root] = 0
for node in bfs:
    for nei in coupl[node]:
        if depth[nei] == -1:
            depth[nei] = depth[node] + 1
            bfs.append(nei)

odd = sum(d & 1 for d in depth)
print min(odd, n - odd) - 1