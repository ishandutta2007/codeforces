n = int(input())
arr = list(map(int, input().split()))

dp = [[1, 1] for i in range(n)]
for i in range(1, n):
    if arr[i] > arr[i - 1]:
        dp[i][1] = dp[i - 1][1] + 1
        dp[i][0] = dp[i - 1][0] + 1
    if i > 1 and arr[i] > arr[i - 2]:
        dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1)
print(max(max(dp[i]) for i in range(n)))