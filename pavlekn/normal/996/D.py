n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(n):
    cur = a[2 * i]
    j = 2 * i + 1
    t = 0
    for k in range(j, n * 2):
        if (a[k] == cur):
            t = k
            break
    for k in range(t, j, -1):
        a[k] = a[k - 1]
        ans += 1
    a[2 * i + 1] = cur
print(ans)