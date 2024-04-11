from sys import stdin, stdout
from math import factorial

# Precompute
N = 55

cyc = [1] * N
for i in range(1, N):
    cyc[i] = factorial(i - 1)


dp = [0] * N
dp[0] = 1
for i in range(1, N):
    for j in range(i):
        dp[i] += dp[j] * cyc[i - j - 1]

# Done Precompute

def kth_cycle(n, k):
    if n == 1:
        return [1]
    
    res = [-1] * n
    res[0] = n - 1

    used = [False] * n
    used[n - 1] = True

    fr = [i for i in range(n)] # from
    fr[n - 1] = 0

    to = [i for i in range(n)] # to
    to[0] = n - 1

    for i in range(1, n - 1):
        cur = factorial(n - i - 2) # number of cycles
        for j in range(n):
            if used[j] or j == fr[i]: # will create a loop
                j += 1
            elif k > cur:
                k -= cur
                j += 1
            else:
                to[fr[i]] = to[j] # next = to check for loops
                fr[to[j]] = fr[i] # to = to check for loops
                res[i] = j
                used[j] = True
                break

    res[n - 1] = fr[n - 1]
    return [x + 1 for x in res]

def solve(n, k):
    if n == 0:
        assert k == 1
        return []
    
    cnt = 1
    while cyc[cnt - 1] * dp[n - cnt] < k:
        k -= cyc[cnt - 1] * dp[n - cnt]
        cnt += 1

    nxt = (k - 1) % dp[n - cnt] + 1
    kth = (k - 1) // dp[n - cnt] + 1

    other = solve(n - cnt, nxt)
    other = [x + cnt for x in other]

    return kth_cycle(cnt, kth) + other

def solve_testcase():
    n, k = [int(x) for x in stdin.readline().split()]
    if dp[n] < k:
        stdout.write("-1\n")
        return

    ans = solve(n, k)
    for i in ans:
        stdout.write(str(i) + " ")
    stdout.write("\n")

def main():
    t = int(stdin.readline())
    for i in range(t):
        solve_testcase()

main()