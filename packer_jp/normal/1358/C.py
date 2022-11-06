def calc(a, r, n):
    return a * n + (n - 1) * n * (n + 3 * r - 2) // 6, a + n * r + n * (n - 1) // 2


t = int(input())
for i in range(t):
    x1, y1, x2, y2 = map(int, input().split())
    a = x1 + y1 - 1
    p1 = calc(0, a, x2 - x1)
    res1 = p1[0] + calc(p1[1], a + x2 - x1 + 1, y2 - y1)[0]
    p2 = calc(0, a + 1, y2 - y1)
    res2 = p2[0] + calc(p2[1], a + y2 - y1, x2 - x1)[0]
    print(res2 - res1 + 1)