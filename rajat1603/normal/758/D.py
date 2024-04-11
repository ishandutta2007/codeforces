n = input()
arr = str(raw_input())
sz = len(arr)
dp = [-1] * sz
def solve(pos):
    if pos < 0:
        return 0
    if dp[pos] != -1:
        return dp[pos]
    res = 1L << 62
    pw = 1
    num = 0
    i = pos
    while i >= 0:
        num += pw * (int(arr[i]) - int('0'))
        pw *= 10
        if num >= n:
            break
        if (arr[i] != '0') or (i == pos):
            res = min(res , solve(i - 1) * n + num)
        i -= 1
    dp[pos] = res
    return res
print solve(sz - 1)