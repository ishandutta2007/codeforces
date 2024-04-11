def solve():
    n, m, k = map(int, input().split())
    a = list(map(int, input().split()))
    k = min(m - 1, k)
    ans = 0
    for i in range(k + 1):
        pos1 = i
        pos2 = n - 1 - (k - i)
        cur_ans = int(1e9 * 2)
        for j in range(m - k):
            cur_ans = min(cur_ans, max(a[pos1 + j], a[pos2 - (m - 1 - k - j)]))
        ans = max(ans, cur_ans)
    print(ans)


t = int(input())
for _ in range(t):
    solve()