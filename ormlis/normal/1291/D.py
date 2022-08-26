s = input()
n = len(s)
dp = [[0] * 26 for _ in range(n + 1)]
for i in range(1, n + 1):
    dp[i] = dp[i - 1].copy()
    dp[i][ord(s[i - 1]) - ord('a')] += 1


for _ in range(int(input())):
    l, r = map(int, input().split())
    l -= 1
    k = [dp[r][i] - dp[l][i] for i in range(26)]
    c = sum((p != 0) for p in k)
    k1 = 0
    k2 = 0
    for j in k:
        if j:
            k1 = j
        k2 += j
    if c > 2 or (l + 1 == r) or (c == 2 and s[l] != s[r - 1]):
        print("Yes")
    else:
        print("No")