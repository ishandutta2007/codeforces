for _ in range(int(input())):
    n, k, d = map(int, input().split())
    a = [int(i) for i in input().split()]
    ans = k + 1
    for i in range(n - d + 1):
        b = set()
        for j in range(i, i + d):
            b.add(a[j])
        ans = min(ans, len(b))
    print(ans)