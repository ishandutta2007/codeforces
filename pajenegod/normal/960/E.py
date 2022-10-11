import sys
range = xrange
input = raw_input 
MOD = 10**9 + 7

def exclusive(A, base = 0, f = lambda a,b: a + b):
    n = len(A)
    B = [base] * n
    for bit in reversed(range(n.bit_length())):
        for i in reversed(range(n)):
            B[i] = B[i // 2]
        for i in range(n & ~(bit == 0)):
            ind = (i >> bit) ^ 1
            B[ind] = f(B[ind], A[i])
    return B

def rerooter(graph, A, f = lambda a,b: a + b):
    n = len(graph)

    P = [0] * n
    bfs = [0]
    for node in bfs:
        for nei in graph[node]:
            if P[node] != nei:
                P[nei] = node
                bfs.append(nei)

    DP = list(A)
    for node in reversed(bfs[1:]):
        DP[P[node]] = f(DP[P[node]], DP[node])
    
    outDP = [[]] * n
    inDP = [[]] * n
    for node in bfs:
        DP[P[node]] = DP[node]
        outDP[node] = DPvec = [DP[nei] for nei in graph[node]]
        inDP[node] = DPexcl_vec = exclusive(DPvec, A[node], f)

        for nei, dp in zip(graph[node], DPexcl_vec):
            DP[nei] = dp
    
    rootDP = [f(inDP[node][0], outDP[node][0]) for node in range(n)]
    return rootDP, outDP, inDP

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
V = inp[ii: ii + n]; ii += n
 
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)
 
def adder((a1,b1), (a2,b2)):
    return a1 + b2, b1 + a2
DP, outDP, inDP = rerooter(coupl, [(1,0)]*n, adder)
 
s = sum(DP[node][0] * V[node] for node in range(n))
for node in range(n):
    for nei, (a1,b1), (a2,b2) in zip(coupl[node], outDP[node], inDP[node]):
        if node < nei:
            s += (a1 * b2 - a2 * b1) * (V[nei] - V[node])
print s % MOD