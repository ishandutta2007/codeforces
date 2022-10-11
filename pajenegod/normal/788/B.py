import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

special = 0
found = [1]*n

coupl = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    found[u] = 0
    found[v] = 0

    if u != v:
        coupl[u].append(v)
        coupl[v].append(u)
    else:
        special += 1

root = 0
while found[root]: root += 1
found[root] = 1
bfs = [root]
for node in bfs:
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = 1
            bfs.append(nei)
 
if all(found):
    print sum(len(c)*(len(c) - 1) for c in coupl)//2 + \
    special * (special - 1)//2 + \
    special * (m - special)
else:
    print 0