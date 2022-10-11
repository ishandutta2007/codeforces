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
 
MOD = 10**9 + 7
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1
A = inp[ii: ii + n]; ii += n
 
coupl = [[] for _ in range(n)]
m = inp[ii]; ii += 1
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
 
SCC = find_SCC(coupl)
 
cost = 0
ways = 1
for scc in SCC:
    mini = min(A[i] for i in scc)
    cost += mini
    count = sum(A[i] == mini for i in scc)
    ways = ways * count % MOD
print cost, ways