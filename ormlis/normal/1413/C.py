from sys import stdin

a = sorted(map(int, stdin.readline().split()))
n = int(stdin.readline())
res = []
b = sorted(map(int, stdin.readline().split()))
for i in range(n):
    res += [(b[i] - ai, i) for ai in a]
res.sort()
cnt = [0] * n
r = 0
c = 0
ans = int(1e18)
for l in range(n * 6):
    while c != n and r < n * 6:
        cnt[res[r][1]] += 1
        if cnt[res[r][1]] == 1:
            c += 1
        r += 1
    if c != n:
        break
    ans = min(ans, res[r - 1][0] - res[l][0])
    cnt[res[l][1]] -= 1
    if cnt[res[l][1]] == 0:
        c -= 1
print(ans)