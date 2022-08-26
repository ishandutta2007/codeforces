def solve():
    n = int(input())
    m = list(map(int, input().split()))
    answ = [0] * n
    answc = 0
    for i in range(n):
        cur = [0] * n
        cur[i] = m[i]
        for j in range(i+1, n):
            cur[j] = min(cur[j-1], m[j])
        for j in range(i-1, -1, -1):
            cur[j] = min(cur[j+1], m[j])
        s = sum(cur)
        if s > answc:
            answc = s
            answ = cur
    print(*answ)



for i in range(1):
    solve()