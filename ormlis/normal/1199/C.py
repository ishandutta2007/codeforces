from sys import stdin

n, i = map(int, stdin.readline().split())
a = list(map(int, stdin.readline().split()))
i *= 8

K = 2 ** (i // n)

a.sort()
b = []
for i in a:
    if not b or b[-1][0] != i:
        b.append([i, 0])
    b[-1][1] += 1

current = 0
for i in range(K, len(b)):
    current += b[i][1]

ans = current
for r in range(K, len(b)):
    current += b[r - K][1]
    current -= b[r][1]
    ans = min(ans, current)
print(ans)