w, h, k = map(int, input().split())
ans = 0
for i in range(k):
    ans += 2 * (w + h - 2)
    w -= 4
    h -= 4
print(ans)