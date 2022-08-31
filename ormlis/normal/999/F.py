def solve():
    n, k = map(int, input().split())
    c = list(map(int, input().split()))
    f = list(map(int, input().split()))
    h = list(map(int, input().split()))
    cnt = {}
    for i in c:
        cnt[i] = cnt.get(i, 0) + 1
    likecolor = {}
    for i in range(n):
        likecolor.setdefault(f[i], []).append(i)
        cnt[f[i]] = cnt.get(f[i], 0)
    ans = 0
    for key, v in likecolor.items():
        n1 = len(v)
        if cnt[key] >= n1 * k:
            ans += n1 * h[k - 1]
            continue
        dp = [[-float("INF")] * (cnt[key]+1) for _ in range(n1 + 1)]
        dp[0][0] = 0
        for i in range(n1):
            j = i + 1
            for e in range(cnt[key] + 1):
                dp[j][e] = max(dp[j][e], dp[i][e])
                for w in range(e + 1, min(cnt[key] + 1, e + k + 1)):
                    dp[j][w] = max(dp[i][e] + h[w - e - 1], dp[j][w])
        ans += dp[n1][cnt[key]]
    print(ans)


solve()