from sys import stdin


def solve():
    s = stdin.readline().strip()
    n = len(s)
    cnt = s.count('1')
    cnt2 = 0
    ans = min(cnt, s.count('0'))
    for i in range(n):
        ans = min(ans, cnt + cnt2)
        ans = min(ans, (n - i - cnt) + (i - cnt2))
        if s[i] == '1':
            cnt -= 1
        else:
            cnt2 += 1
    print(ans)


tt = int(stdin.readline())
for _ in range(tt):
    solve()