t = int(input())
for i in range(t):
    n = int(input())
    w = list(map(int, input().split()))
    a = [0 for i in range(n + 1)]
    b = [0 for i in range(2 * n + 1)]
    for v in w:
        a[v] += 1
    for j in range(n + 1):
        for k in range(j + 1):
            if j == k:
                b[j + k] += a[j] // 2
            else:
                b[j + k] += min(a[j], a[k])
    print(max(b))