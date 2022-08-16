mod = 10**9 + 7

def ktree(l, a, dp, k, d):
    if (l < 0):
        return 0
    if (l == 0 and a == 0):
        return 0
    if (l == 0 and a == 1):
        return 1
    if (dp[l][a] != -1):
        return dp[l][a]

    sum = 0

    for i in range(1, k+1):
        if i >= d:
            sum += ktree(l-i, 1, dp, k, d)
        else:
            sum += ktree(l-i, a, dp, k, d)

    dp[l][a] = sum
    return dp[l][a]

s = str(input())

l = s.split()

n = int(l[0])
k = int(l[1])
d = int(l[2])

dp = [[-1 for i in range(2)] for i in range(101)]

print(ktree(n, 0, dp, k, d) % mod)