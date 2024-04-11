from sys import stdin


def solve():
    n = int(stdin.readline())
    m = list(map(int, stdin.readline().split()))
    msl = [-1] * n
    msp = [n] * n
    q = []
    for i in range(n):
        while q and m[q[-1]] > m[i]:
            q.pop()
        if q:
            msl[i] = q[-1]
        q.append(i)
    q = []
    for i in range(n - 1, -1, -1):
        while q and m[q[-1]] > m[i]:
            q.pop()
        if q:
            msp[i] = q[-1]
        q.append(i)

    dp1 = [0] * n
    for i in range(n):
        dp1[i] = m[i] * (i - msl[i])
        if msl[i] != -1:
            dp1[i] += dp1[msl[i]]
    dp2 = [0] * n
    for i in range(n - 1, -1, -1):
        dp2[i] += m[i] * (msp[i] - i)
        if msp[i] != n:
            dp2[i] += dp2[msp[i]]
    ansm = 0
    answc = 0
    for i in range(n):
        cur = dp1[i] + dp2[i] - m[i]
        if cur > answc:
            answc = cur
            ansm = i
    i = ansm
    cur = [0] * n
    cur[i] = m[i]
    for j in range(i + 1, n):
        cur[j] = min(cur[j - 1], m[j])
    for j in range(i - 1, -1, -1):
        cur[j] = min(cur[j + 1], m[j])
    print(*cur)


for i in range(1):
    solve()