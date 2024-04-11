import sys
range = xrange
input = raw_input

n = int(input())
M = [[int(x) for x in input()] for _ in range(n)]

def floyd_warshall(n, dist):
    dist = [[d if d > 0 else 1000000000 for d in line] for line in dist]
    for i in range(n):
        dist[i][i] = 0
    
    pred = [[-1] * n for _ in range(n)]

    for u in range(n):
        for v in range(n):
            if dist[u][v]:
                pred[u][v] = u

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    pred[i][j] = pred[k][j]
    return dist, pred


dist, pred = floyd_warshall(n, [list(a) for a in M])

m = int(input())
P = [int(x) - 1 for x in input().split()]


DP = [-1]*m
DP[0] = -2

pairs = []
for i in range(m):
    if DP[i] != -1:
        d = dist[P[i]]
        j = i + 1
        while j < m and d[P[j]] == j - i:
            if DP[j] == -1:
                DP[j] = i
            j += 1

k = m - 1
ans = []
while k >= 0:
    ans.append(k)
    k = DP[k]

print len(ans)
print ' '.join(str(P[x] + 1) for x in ans[::-1])