
n = int(raw_input())
ans = 0
cur = 0
for i in range(n):
    z = map(int, raw_input().split())
    cur += z[1] - z[0]
    ans = max(ans, cur)
print ans