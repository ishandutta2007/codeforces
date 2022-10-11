# Taken from pyrival/graphs/scc.py
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

class TwoSat:
    def __init__(self, n):
        self.n = n
        self.graph = [[] for _ in range(2 * n)]

    def _imply(self, x, y):
        self.graph[x].append(y if y >= 0 else 2 * self.n + y)

    def either(self, x, y):
        """either x or y must be True"""
        self._imply(~x, y)
        self._imply(~y, x)

    def set(self, x):
        """x must be True"""
        self._imply(~x, x)

    def solve(self):
        SCC = find_SCC(self.graph)
        order = [0] * (2 * self.n)
        for i, comp in enumerate(SCC):
            for x in comp:
                order[x] = i
        
        for i in range(self.n):
            if order[i] == order[~i]:
                return False, None
        return True, [+(order[i] > order[~i]) for i in range(self.n)]

import sys
input = sys.stdin.readline
 
n,m = [int(x) for x in input().split()]
 
sat = TwoSat(m+1)
 
A = [[int(x) for x in input().split()][1:] for _ in range(n)]
for i in range(n-1):
    a = A[i]
    b = A[i+1]
    for j in range(min(len(a), len(b))):
        if a[j] != b[j]:
            if a[j] < b[j]:
                sat.either(a[j], ~b[j])
            else:
                sat.set(a[j])
                sat.set(~b[j])
            break
    else:
        if len(a)>len(b):
            print('No')
            sys.exit()
 
possible, values = sat.solve()
if possible:
    print('Yes')
    big = [i for i in range(1,m+1) if values[i]]
    print(len(big))
    print(' '.join(str(x) for x in big))
else:
    print('No')