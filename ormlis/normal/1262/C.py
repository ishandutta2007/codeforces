def solve():
    n, k = map(int, input().split())
    arr = list(map(lambda x: 1 if x == '(' else -1, input().strip()))
    cur = 1
    ans = []
    for i in range((k - 1) * 2):
        for j in range(i, n):
            if arr[j] == cur:
                arr[j], arr[i] = arr[i], arr[j]
                ans.append((i + 1, j + 1))
                break
        cur = -1 if cur == 1 else 1
    a = n - (n - (k - 1) * 2) // 2
    for i in range((k - 1) * 2, a):
        for j in range(i, n):
            if arr[j] == 1:
                arr[j], arr[i] = arr[i], arr[j]
                ans.append((i + 1, j + 1))
                break
    print(len(ans))
    for el in ans:
        print(*el)


t = int(input())
for _ in range(t):
    solve()