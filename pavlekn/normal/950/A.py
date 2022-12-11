l, r, a = map(int, input().split())
ans = min(l, r) * 2
if (max(l, r) - min(l, r) > a):
    print(ans + a * 2)
else:
    ans = max(l, r) * 2 + ((a - max(l, r) + min(l, r)) // 2) * 2
    print(ans)