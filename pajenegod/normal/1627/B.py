import sys

t = int(input())
for _ in range(t):
    n,m = [int(x) for x in input().split()]

    dist = [0] * (n * m)
    for i in range(n):
        for j in range(m):
            d1 = max(i, n - i - 1)
            d2 = max(j, m - j - 1)
            dist[i * m + j] = d1 + d2
    
    print(*sorted(dist))