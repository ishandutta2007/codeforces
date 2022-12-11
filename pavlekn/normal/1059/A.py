n, l, k = map(int, input().split())
ans = 0
pr = 0
for i in range(n):
    ti, li = map(int, input().split())
    ans += (ti - pr) // k
    pr = ti + li
ans += (l - pr) // k
print(ans)