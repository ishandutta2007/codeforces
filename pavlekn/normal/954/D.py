from collections import deque
def bfs(s, level):
    level[s] = 0
    stack = deque([s])
    while stack:
        v = stack.popleft()
        for w in g[v]:
            if level[w] is -1:
                stack.append(w)
                level[w] = level[v] + 1
n, m, s, t = map(int, input().split())
g = []
for i in range(n):
    g.append(set())
for i in range(m):
    u, v = map(int, input().split())
    g[u - 1].add(v - 1)
    g[v - 1].add(u - 1)
a = [-1] * n
b = [-1] * n
bfs(s - 1, a)
bfs(t - 1, b)
cur = a[t - 1]
ans = 0
for i in range(n):
    for j in range(i + 1, n):
        if (min(a[i] + b[j] + 1, a[j] + b[i] + 1) >= cur and (j not in g[i])):
            ans += 1
print(ans)