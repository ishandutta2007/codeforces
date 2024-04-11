import sys
from collections import deque
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

n = inp[ii]
ii += 1
m = inp[ii]
ii += 1

coupl = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1
    ii += 1
    v = inp[ii] - 1
    ii += 1
    coupl[u].append(v)


found = [0]*n
indeg = [0]*n

order = []
for root in range(n):
    if found[root]:
        continue
    tmp = []
    
    dfs = []
    dfs.append(root)
    while dfs:
        node = dfs.pop()
        if node < 0:
            tmp.append(~node)
            continue
        if found[node]:
            continue
        found[node] = 1
        dfs.append(~node)
        for nei in coupl[node]:
            dfs.append(nei)
    order += tmp

index = [0]*n
for i in range(n):
    index[order[i]] = i

ii = 2
out = [1]*m
for _ in range(m):
    u = inp[ii] - 1
    ii += 1
    v = inp[ii] - 1
    ii += 1
    if index[u] < index[v]:
        out[_] = 2
print 2 if any(o == 2 for o in out) else 1
print ' '.join(str(o) for o in out)