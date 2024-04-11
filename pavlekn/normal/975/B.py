b = list(map(int, input().split()))
ans = 0
for i in range(14):
    a = []
    for k in range(14):
        a.append(b[k])
    count = a[i]
    a[i] = 0
    h = count % 14
    h1 = count // 14
    for j in range(i + 1, i + 1 + 14):
        if (j < i + 1 + h):
            j %= 14
            a[j] += h1 + 1
        else:
            j %= 14
            a[j] += h1
    n_ans = 0
    for k in range(14):
        if (a[k] % 2 == 0):
            n_ans += a[k]
    ans = max(ans, n_ans)
print(ans)