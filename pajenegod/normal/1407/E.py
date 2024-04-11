import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

coupl = [[] for _ in range(n)]
V = []
CE = []
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    w = inp[ii]; ii += 1

    eind = len(V)
    coupl[u].append(eind)
    coupl[v].append(eind ^ 1)
    V.append(v)
    V.append(u)
    CE.append(w)

dist = [-1] * n

C = [-1] * n
C[-1] = 0

bfs = [n - 1]
for node in bfs:
    if dist[node] == -1:
        D = -1
        for eind in coupl[node]:
            v = V[eind]
            d = dist[v]
            foward = eind & 1 == 0
            edge_color = CE[eind >> 1]

            if foward and d != -1 and edge_color == C[node]:
                if D == -1 or d < D:
                    D = d
        dist[node] = D + 1
 
        for eind in coupl[node]:
            v = V[eind]
            d = dist[v]
            foward = eind & 1 == 0
            edge_color = CE[eind >> 1]
            
            if not foward:
                if C[v] == -1:
                    C[v] = 1 - edge_color
                if C[v] == edge_color:
                    bfs.append(v)

print dist[0]

C = [c if c >= 0 else 0 for c in C]
print ''.join(str(x) for x in C)