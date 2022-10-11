import sys
import os
range = xrange
input = raw_input
 
S = os.read(0, 2**25)
n = 0
i = 0
while S[i] >= '0':
    n = 10 * n + ord(S[i]) - 48
    i += 1
i += 2
 
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = v = 0
    while ord(S[i]) >= 48:
        u = 10 * u + ord(S[i]) - 48
        i += 1
    i += 1
    while ord(S[i]) >= 48:
        v = 10 * v + ord(S[i]) - 48
        i += 1
    i += 2
    coupl[u - 1].append(v - 1)
    coupl[v - 1].append(u - 1)
 
bfs = [0]
children = coupl
for node in bfs:
    for nei in coupl[node]:
        d = coupl[nei]
        d[d.index(node)] = d[-1]
        d.pop()
        bfs.append(nei)
 
family = [2]*n
for node in reversed(bfs):
    for child in children[node]:
        family[node] += family[child]
 
out = [2 * n - 1]*(2 * n)
out[1] = 2 * n 
for node in bfs:
    r = out[2 * node]
    l = r - (family[node] - 1)
    for child in children[node]:
        out[2 * child] = l = l + family[child] - 1
        out[2 * child + 1] = r
        r -= 1
    out[2 * node] = r
 
import cStringIO
stream = cStringIO.StringIO()
f = stream.write
for x in out:
    f(str(x))
    f(' ')
 
os.write(1, stream.getvalue())