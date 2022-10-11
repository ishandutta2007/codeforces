import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
m = int(inp[ii]); ii += 1

M = [0]*(m + 2)
for _ in range(n):
    M.append(0)
    for c in inp[ii]:
        if c == '#':
            M.append(0)
        elif c == '.':
            M.append(1)
        else:
            M.append(ord(c) - 47)
    ii += 1
    M.append(0)
M += [0]*(m + 2)

n += 2
m += 2

A = []
B = []
C = []
for i in range(n*m):
    if M[i] == 2:
        A.append(i)
    elif M[i] == 3:
        B.append(i)
    elif M[i] == 4:
        C.append(i)

inf = 10**8

Adist = [inf]*(n*m)
Bdist = [inf]*(n*m)
Cdist = [inf]*(n*m)

def dister(bfs, dist):
    for node in bfs:
        dist[node] = 0
    for node in bfs:
        d = dist[node] + 1
        for nei in node - 1, node + 1, node - m, node + m:
            if M[nei] and dist[nei] == inf:
                dist[nei] = d
                bfs.append(nei)
dister(list(A), Adist)
dister(list(B), Bdist)
dister(list(C), Cdist)

besta = inf
for i in range(n*m):
    besta = min(besta, Adist[i] + Bdist[i] + Cdist[i] - 2)

def opter(dist1, dist2):
    besta = inf
    for i in range(n*m):
        besta = min(besta, dist1[i] + dist2[i] - 1)
    return besta

besta1 = opter(Adist, Bdist)
besta2 = opter(Adist, Cdist)
besta3 = opter(Bdist, Cdist)

alt1 = besta
alt2 = besta1 + besta2
alt3 = besta1 + besta3
alt4 = besta2 + besta3

alt = min(alt1, alt2, alt3, alt4)
print alt if alt < 10**7 else -1