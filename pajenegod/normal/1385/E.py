import sys
range = xrange
input = raw_input

def find_SCC(coupl):
    SCC, S, P = [], [], []
    depth = [0] * len(coupl)
 
    stack = list(range(len(coupl)))
    while stack:
        node = stack.pop()
        if node < 0:
            d = depth[~node] - 1
            if P[-1] > d:
                SCC.append(S[d:])
                del S[d:], P[-1]
                for node in SCC[-1]:
                    depth[node] = -1
        elif depth[node] > 0:
            while P[-1] > depth[node]:
                P.pop()
        elif depth[node] == 0:
            S.append(node)
            P.append(len(S))
            depth[node] = len(S)
            stack.append(~node)
            stack += coupl[node]
    return SCC[::-1]

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    
    coupl = [[] for _ in range(n)]
    V = []
    T = []
    for _ in range(m):
        typ = inp[ii]; ii += 1
        u = inp[ii] - 1; ii += 1
        v = inp[ii] - 1; ii += 1
        T.append(typ)
        V.append(v)
        V.append(u)

        if typ:
            coupl[u].append(v)
    SCC = find_SCC(coupl)
    inSCC = [0]*n
    for j,scc in enumerate(SCC):
        if len(scc) > 1:
            out.append('NO')
            break
        for node in scc:
            inSCC[node] = j
    else:
        out.append('YES')
        for i in range(m):
            u = V[2 * i + 1]
            v = V[2 * i]
            if inSCC[u] > inSCC[v]:
                u,v = v,u
            out.append("%d %d" % (u + 1, v + 1))
print '\n'.join(out)