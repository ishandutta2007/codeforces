import sys
range = xrange
input = raw_input

# awfdsajgnjisgjnsfdin

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
for node in bfs:
    for nei in coupl[node]:
        del coupl[nei][coupl[nei].index(node)]
        bfs.append(nei)

counter = [0] * n
for node in reversed(bfs):
    counter[node] += 1
    for nei in coupl[node]:
        counter[node] += counter[nei]

nhalf = n // 2

for node in range(n):
    vals = [counter[nei] for nei in coupl[node]]
    vals.append(n - 1 - sum(vals))
    if max(vals) <= nhalf:
        break
root = node

for node in reversed(bfs):
    for nei in coupl[node]:
        coupl[nei].append(node)

found = [0] * n
depth = [0] * n

order = []
stack = [root]
while stack:
    node = stack.pop()
    if found[node]:
        continue
    found[node] = 1
    order.append(node)

    for nei in coupl[node]:
        if not found[nei]:
            depth[nei] = depth[node] + 1
            stack.append(nei)
    stack += coupl[node]

ans = [-1] * n
for i in range(n):
    ans[order[i - nhalf]] = order[i]

print 2 * sum(depth)
print ' '.join(str(x + 1) for x in ans)