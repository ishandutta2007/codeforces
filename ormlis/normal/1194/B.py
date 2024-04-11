def solve():
    n, m = map(int, input().split())
    s = [input().strip() for i in range(n)]
    ans = list(map(lambda x: x.count('.'), s))
    ans2 = [0] * m
    for i in range(n):
        for j in range(m):
            if s[i][j] == '.':
                ans2[j] += 1
    mini = min(ans)
    minj = min(ans2)
    answ = mini + minj
    for i in range(n):
        if ans[i] != mini:
            continue
        for j in range(m):
            if s[i][j] == '.' and ans2[j] == minj:
                answ -= 1
                return print(answ)
    print(answ)


for _ in range(int(input())):
    solve()