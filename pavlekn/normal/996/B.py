n = int(input())
a = list(map(int, input().split()))
m = a[0]
for i in range(n):
    m = min(m, a[i])
if (m == 0):
    ans = 1
    for i in range(n):
        if (a[i] - i <= 0):
            ans = i + 1
            break
    print(ans)
else:
    cur = m % n
    for i in range(cur, cur + n):
        d = i - cur
        i %= n
        if (a[i] - d - m <= 0):
            ans = i + 1
            break
    print(ans)