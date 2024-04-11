import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
k = inp[ii]; ii += 1

coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

root = 0
bfs = [root]
P = [-1]*n
for node in bfs:
    for nei in coupl[node]:
        del coupl[nei][coupl[nei].index(node)]
        bfs.append(nei)
        P[nei] = node

size = [1]*n
for node in reversed(bfs[1:]):
    size[P[node]] += size[node]

depth = [0]*n
for node in bfs[1:]:
    depth[node] = depth[P[node]] + 1

score = [depth[node] - size[node] + 1 for node in range(n)]

print sum(sorted(score, reverse = True)[:k])