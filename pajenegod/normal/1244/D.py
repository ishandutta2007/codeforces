import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0 

n = inp[ii]; ii += 1
C = inp[ii:ii + 3 * n]; ii += 3 * n

coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

if any(len(c)>2 for c in coupl):
    print -1
    sys.exit()

root = 0
found = [0]*n
found[root] = 1
bfs = [root]

for node in bfs:
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = 1
            bfs.append(nei)

root = bfs[-1]
found = [0]*n
found[root] = 1
bfs = [root]

for node in bfs:
    for nei in coupl[node]:
        if not found[nei]:
            found[nei] = 1
            bfs.append(nei)


best = -1
bestc1 = -1
bestc2 = -1

for c1 in range(3):
    for c2 in range(3):
        if c1 == c2:
            continue
        c3 = 3 - (c1 + c2)
        s = 0
        for i in range(n):
            j = i % 3
            if j == 0:
                s += C[bfs[i] + c1 * n]
            elif j == 1:
                s += C[bfs[i] + c2 * n]
            else:
                s += C[bfs[i] + c3 * n]
        if best == -1 or s < best:
            best = s
            bestc1 = c1
            bestc2 = c2

print best

c1 = bestc1
c2 = bestc2
c3 = 3 - c1 - c2

color = [0]*n
for i in range(n):
    j = i % 3
    if j == 0:
        color[bfs[i]] = c1
    elif j == 1:
        color[bfs[i]] = c2
    else:
        color[bfs[i]] = c3

print ' '.join(str(x + 1) for x in color)