import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

coupl = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

s = inp[ii] - 1; ii += 1
t = inp[ii] - 1; ii += 1

ds = inp[ii]; ii += 1
dt = inp[ii]; ii += 1

found = [-1]*n

found[s] = s
found[t] = t

for root in coupl[s] + coupl[t]:
    if found[root] >= 0:
        continue
    found[root] = root
    bfs = [root]
    for node in bfs:
        for nei in coupl[node]:
            if found[nei] == -1:
                found[nei] = root
                bfs.append(nei)

A = {found[nei] for nei in coupl[s]} 
B = {found[nei] for nei in coupl[t]}

A.discard(t)
B.discard(s)

C = A & B
A -= C
B -= C

Acoupl = []
Bcoupl = []

A = list(A)
B = list(B)
C = list(C)

if C:
    node = C.pop()
    Acoupl.append(node)
    Bcoupl.append(node)
else:
    Acoupl.append(t)
    #Bcoupl.append(s)

Acoupl += A
Bcoupl += B
while C:
    if len(Acoupl) < ds:
        Acoupl.append(C.pop())
    else:
        Bcoupl.append(C.pop())

if len(Acoupl) > ds or len(Bcoupl) + (t in Acoupl) > dt:
    print 'No'
    sys.exit()

out = ['Yes']

Acoupl = set(Acoupl)
Bcoupl = set(Bcoupl)

for nei in coupl[s]:
    if found[nei] in Acoupl:
        out.append('%d %d' % (s + 1, nei + 1))
        Acoupl.remove(found[nei])

for nei in coupl[t]:
    if found[nei] in Bcoupl:
        out.append('%d %d' % (t + 1, nei + 1))
        Bcoupl.remove(found[nei])

P = [-1]*n
P[s] = s
P[t] = t

for node in range(n):
    if P[node] >= 0:
        continue
    color = found[node]
    P[node] = node
    bfs = [node]
    for node in bfs:
        for nei in coupl[node]:
            if P[nei] == -1 and found[nei] == color:
                P[nei] = node
                bfs.append(nei)
                out.append('%d %d' % (node + 1, nei + 1))
print '\n'.join(out)