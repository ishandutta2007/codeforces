import sys
input = sys.stdin.readline

"""
Given a directed graph, find_SCC returns a list of lists containing 
the strongly connected components in topological order.
Note that this implementation can be also be used to check if a directed graph is a
DAG, and in that case it can be used to find the topological ordering of the nodes.
"""

def find_SCC(graph):
    SCC, S, P = [], [], []
    depth = [0] * len(graph)
 
    stack = list(range(len(graph)))
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
            stack += graph[node]
    return SCC[::-1]

t = int(input())
for cas in range(t):
    input()
    n,m = [int(x) for x in input().split()]
    coupl = [[] for _ in range(n)]
    self_loop = [0] * n
    for _ in range(m):
        u,v = [int(x) - 1 for x in input().split()]
        if u != v:
            coupl[u].append(v)
        else:
            self_loop[u] = 1

    SCC = find_SCC(coupl)
    k = len(SCC)

    inSCC = [-1] * n
    for j,scc in enumerate(SCC):
        for node in scc:
            inSCC[node] = j

    DP = [0] * k
    DP[inSCC[0]] = 1
    is_infinite = [+(len(scc) > 1 or self_loop[scc[0]]) for scc in SCC]

    inf = 10**9

    for scc in SCC:
        for node in scc:
            scc1 = inSCC[node]
            if DP[scc1]:
                for nei in coupl[node]:
                    scc2 = inSCC[nei]
                    DP[scc2] = min(inf, DP[scc2] + DP[scc1])
                    is_infinite[scc2] |= is_infinite[scc1]

    ans = []
    for node in range(n):
        dp = DP[inSCC[node]]
        infi = is_infinite[inSCC[node]]

        if dp == 0:
            ans.append(0)
        elif infi:
            ans.append(-1)
        elif dp == 1:
            ans.append(1)
        else:
            ans.append(2)

    print ' '.join(str(x) for x in ans)