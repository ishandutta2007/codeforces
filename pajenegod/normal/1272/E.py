import sys
range = xrange
input = raw_input

n = int(input())
A = [0] + [int(x) for x in input().split()]

reach = [[] for _ in range(n + 1)]
for i in range(1, n + 1):
    if 1 <= i - A[i]:
        reach[i - A[i]].append(i)
    if i + A[i] <= n:
        reach[i + A[i]].append(i)

def bfs(par):
    dist = [-1]*(n + 1) 
    nesta = []
    for i in range(1, n + 1):
        if A[i] & 1 == par:
            dist[i] = 0
            nesta += reach[i]
    
    d = 1
    cur = nesta
    while cur:
        nesta = []
        for i in cur:
            if dist[i] < 0:
                dist[i] = d
                nesta += reach[i]
        cur = nesta
        d += 1
    return dist

reach_odd = bfs(1)
reach_even = bfs(0)

ans = []
for i in range(1, n + 1):
    if A[i] & 1:
        ans.append(reach_even[i])
    else:
        ans.append(reach_odd[i])
print ' '.join(str(x) for x in ans)