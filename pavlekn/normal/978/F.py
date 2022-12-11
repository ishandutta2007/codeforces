def main():
    n, k = map(int, input().split())
    g = []
    for i in range(n):
        g.append([])
    a = list(map(int, input().split()))
    b = []
    for i in range(n):
        b.append([a[i], i])
    b.sort()
    m = {}
    count = 0
    for i in range(n):
        if (i != 0 and b[i][0] == b[i - 1][0]):
            count += 1
        else:
            count = 0
        m[b[i][1]] = i - count
    for i in range(k):
        u, v = map(int, input().split())
        g[u - 1].append(v - 1)
        g[v - 1].append(u - 1)
    ans = [0] * n
    for i in range(n):
        s = m[i]
        for el in g[i]:
            if (m[el] < m[i]):
                s -= 1
        ans[i] = s
    for i in range(n):
        print(ans[i], end=' ')
main()