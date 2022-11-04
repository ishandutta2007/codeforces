s = input()
n = len(s)

dp = [[0 for i in range(n - le + 1)] for le in range(n + 1)]
ans = [0 for i in range(n + 1)]

for le in range(1, n + 1):
    for l in range(0, n - le + 1):
        r = l + le
        if s[l] != s[r - 1]:
            continue
        if le == 1:
            dp[1][l] = 1
            ans[1] += 1
        elif le == 2:
            ans[2] += 1
            dp[2][l] = 2
        elif dp[le - 2][l + 1]:
            v = 1
            m = (l + r) // 2
            st = m + 1 if le & 1 else m
            le2 = m - l
            q = dp[le2][l]
            if q:
                v = q + 1

            ans[v] += 1
            dp[le][l] = v


for i in range(n - 1, 0, -1):
    ans[i] += ans[i + 1]

print(*ans[1:])