import sys
range = xrange
input = raw_input
 
def toposort(graph):
    n = len(graph)
    res = []; found = [0] * n
 
    for i in range(n):
        if found[i]:
            continue
        stack = [10**9, i]
        for node in iter(stack.pop, 10**9):
            if node < 0:
                res.append(~node)
            elif not found[node]:
                found[node] = 1
                stack.append(~node)
                stack += graph[node]
    
    # Check for cycle
    for node in res:
        if any(found[nei] for nei in graph[node]):
            return None
        found[node] = 0
 
    return res[::-1]
 
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
 
coupl1 = [[] for _ in range(n)]
coupl2 = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl1[u].append(v)
    coupl2[v].append(u)
 
order = toposort(coupl1)
if order is None:
    print -1
    sys.exit()
 
seen1 = list(range(n))
seen2 = list(range(n))
for node in order:
    for nei in coupl1[node]:
        seen1[nei] = min(seen1[node], seen1[nei])
 
for node in reversed(order):
    for nei in coupl2[node]:
        seen2[nei] = min(seen2[node], seen2[nei])
 
seen = [+(seen1[node] == seen2[node] == node) for node in range(n)]
print sum(seen)
print ''.join('A' if c else 'E' for c in seen)