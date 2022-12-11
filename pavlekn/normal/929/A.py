n, k = map(int, input().split())
a = list(map(int, input().split()))
ans = 1
cur = 0
i = 1
while (True):
    while (i < n and a[cur] + k >= a[i]):
        i += 1
    i -= 1
    if (i == cur):
        print(-1)
        break
    if (i == n - 1):
        print(ans)
        break
    else:
        ans += 1
        cur = i
        i = cur + 1