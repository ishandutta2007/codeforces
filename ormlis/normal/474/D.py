t, k = map(int, input().split())
MOD = int(1e9) + 7


def madd(a, b):
    if a + b >= MOD:
        return a + b - MOD
    return a + b


def msub(a, b):
    if a >= b:
        return a - b
    return a - b + MOD


dp = [0] * 100001
dp[0] = 1
prefix = [0] * 100001
for i in range(1, 100001):
    dp[i] = dp[i - 1]
    if i >= k:
        dp[i] = madd(dp[i], dp[i - k])
    prefix[i] = madd(prefix[i - 1], dp[i])
for _ in range(t):
    a, b = map(int, input().split())
    print(msub(prefix[b], prefix[a - 1]))