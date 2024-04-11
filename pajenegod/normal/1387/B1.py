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

P = [-1] * n
root = 0
bfs = [root]
P[root] = root
for node in bfs:
    for nei in coupl[node]:
        del coupl[nei][coupl[nei].index(node)]
        bfs.append(nei)
        P[nei] = node


ans = list(range(n))
cost = 0

for node in reversed(bfs):
    if ans[node] != node:
        continue
    cost += 2
    if node != root:
        p = P[node]
    else:
        p = coupl[node][0]
    ans[node],ans[p] = ans[p],ans[node]

print cost
print ' '.join(str(x + 1) for x in ans)