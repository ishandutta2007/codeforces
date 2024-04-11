n, a, b = map(int, input().split())
s = list(map(int, input().split()))
x1 = s[0]
s = s[1:]
ans = 0
cur = sum(s) + x1
s.sort()
i = len(s) - 1
while True:
    if ((x1 * a) >= cur * b):
        print(ans)
        break
    cur -= s[i]
    i -= 1
    ans += 1