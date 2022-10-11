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
 
found = [0]*n
found[root] = 1
bfs = [root]
for _ in range(2):
    for node in list(bfs):
        for nei in coupl[node]:
            if not found[nei]:
                found[nei] = 1
                bfs.append(nei)
 
P = [-1]*n
P[root] = root
bfs = [root]
for node in bfs:
    for nei in coupl[node]:
        if P[nei] == -1:
            P[nei] = node
            bfs.append(nei)

marker = [0]*n
deg = [len(c) for c in coupl]
found2 = [0]*n

for node in reversed(bfs):
    if found[node] or marker[node] or any(marker[nei] for nei in coupl[node]):
        continue
    
    node = P[node]
    marker[node] = 1
    found2[node] = 1
    
    for nei in coupl[node]:
        found2[nei] = 1 
 
print sum(marker)