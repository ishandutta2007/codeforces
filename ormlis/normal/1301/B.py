def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    ans = 0
    for i in range(n):
        if i:
            if a[i] != -1 and a[i - 1] != -1:
                ans = max(abs(a[i] - a[i - 1]), ans)
        if a[i] == -1:
            if i and a[i - 1] != -1:
                b.append(a[i - 1])
            if i != n - 1 and a[i + 1] != -1:
                b.append(a[i + 1])
    if not b:
        return print(0, 1)
    ma = max(b)
    mi = min(b)
    s = (ma + mi) // 2
    print(max(ma - s, s - mi, ans), s)


for i in range(int(input())):
    solve()