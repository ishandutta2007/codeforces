from collections import deque
import sys
input = sys.stdin.readline
inf = int(1e9)
for i in range(int(input())):
    n, m, a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    c -= 1
    cost = list(map(int, input().split()))
    g = [[] for _ in range(n)]
    for i in range(m):
        a2, b2 = map(int, input().split())
        g[a2 - 1].append(b2 - 1)
        g[b2 - 1].append(a2 - 1)
    def bfs(st):
        Q = deque(maxlen=n)
        lv = [-1] * n
        Q.append(st)
        lv[st] = 0
        while Q:
            cur = Q.popleft()
            for to in g[cur]:
                if lv[to] == -1:
                    lv[to] = lv[cur] + 1
                    Q.append(to)
        return lv
    lvA = bfs(a)
    lvB = bfs(b)
    lvC = bfs(c)
    # print(lvA, lvB, lvC)
    ans = int(1e18)
    cost.sort()
    cost.insert(0, 0)
    for i in range(1, len(cost)):
        cost[i] += cost[i - 1]
    # print(cost)
    for i in range(n):
        d1 = lvB[i]
        d2 = lvA[i] + lvC[i]
        if d1 + d2 >= len(cost):
            continue
        # print(f'i={i}, d1={d1}, d2={d2}')
        ans = min(ans, cost[d1] * 2 + cost[d1 + d2] - cost[d1])
    print(ans)