import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

W = inp[ii: ii + n]; ii += n
X = inp[ii + 0: ii + 2 * m: 2]
Y = inp[ii + 1: ii + 2 * m: 2]

V = []
coupl = [[] for _ in range(n)]
for i in range(m):
    u = X[i] - 1
    v = Y[i] - 1
    eind = 2 * i
    V.append(v)
    V.append(u)
    coupl[u].append(eind)
    coupl[v].append(eind ^ 1)


cap = [W[j] - len(coupl[j]) for j in range(n)]
bfs = [j for j in range(n) if cap[j] >= 0]

found = [0]*m
order = []

for node in bfs:
    for eind in coupl[node]:
        if not found[eind >> 1]:
            found[eind >> 1] = 1
            order.append(eind >> 1)
        nei = V[eind]
        cap[nei] += 1
        if cap[nei] == 0:
            bfs.append(nei)

if len(bfs) == n:
    print 'ALIVE'
    print ' '.join(str(x + 1) for x in reversed(order))
else:
    print 'DEAD'