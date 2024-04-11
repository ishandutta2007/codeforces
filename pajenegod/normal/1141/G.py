from __future__ import print_function
import os,sys,atexit

if sys.version_info[0] < 3:
    range = xrange
    from cStringIO import StringIO as BytesIO
    sys.stdout = BytesIO()
else:
    from io import BytesIO
    sys.stdout = BytesIO()
    _write = sys.stdout.write
    sys.stdout.write = lambda s: _write(s.encode())
atexit.register(lambda: os.write(1, sys.stdout.getvalue()))

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline

n,k = [int(x) for x in input().split()]

coupl = [[] for _ in range(n)]
edge_ind = [[] for _ in range(n)]
for _ in range(n-1):
    u,v = [int(x)-1 for x in input().split()]
    coupl[u].append(v)
    coupl[v].append(u)
    edge_ind[u].append(_)
    edge_ind[v].append(_)

root = 0
order = [root]
stack = [root]
found = [False]*n

found[root]=True
while stack:
    node = stack.pop()
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = True
            order.append(nei)
            stack.append(nei)
degs = sorted(range(n),key=lambda i:len(coupl[i]),reverse=True)
free = [False]*n

for i in degs[:k]:
    free[i] = True

colors_needed = len(coupl[degs[k]])
colors_used = [set() if not free[_] else None for _ in range(n)]
edge_color = [0]*(n-1)

for node in order:
    if not free[node]:
        next_color = 1
        while next_color in colors_used[node]:next_color += 1
    else:
        next_color = colors_needed
    
    edge_indices = edge_ind[node]
    neighbours = coupl[node]
    for i in range(len(coupl[node])):
        edge_i = edge_indices[i]
        if edge_color[edge_i]==0:
            nei = neighbours[i]
            edge_color[edge_i] = next_color
            if not free[nei]:
                colors_used[nei].add(next_color)
            if not free[node]:
                next_color += 1
                while next_color in colors_used[node]:next_color += 1
print(colors_needed)
for c in edge_color:
    sys.stdout.write(str(c))
    sys.stdout.write(" ")