import sys

inp = [int(x) for x in sys.stdin.buffer.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1

    iii = ii

    graph = [[] for _ in range(n)]
    for _ in range(n - 1):
        u = inp[ii] - 1; ii += 1
        v = inp[ii] - 1; ii += 1
        graph[u].append(v)
        graph[v].append(u)

    if any(len(d) >= 3 for d in graph):
        print(-1)
        continue
    
    root = 0
    while len(graph[root]) > 1:
        root += 1
    
    bfs = [root]
    depth = [0] * n
    for node in bfs:
        for nei in graph[node]:
            graph[nei].remove(node)
            depth[nei] = 1 + depth[node]
        bfs += graph[node]
    
    out = []
    for _ in range(n - 1):
        u = inp[iii] - 1; iii += 1
        v = inp[iii] - 1; iii += 1

        d = min(depth[u], depth[v])
        out.append(2 if d & 1 else 3)

    print(*out)