n, r = map(int, input().split())
a = input().split()
ans = []
for i in range(n):
    res = r
    for j in range(i):
        if (abs(int(a[j]) - int(a[i])) <= 2 * r):
            res = max(res, ans[j] + (4 * r * r - abs(int(a[j]) - int(a[i])) ** 2) ** 0.5)
    ans.append(res)
for i in range(n):
    print(ans[i], end = ' ')