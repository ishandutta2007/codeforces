n, k = map(int, input().split())
a = list(map(int, input().split()))
t = list(map(int, input().split()))
l = 0
s = 0
for i in range(n):
    if (t[i] or i < k):
        s += a[i]
ans = s
r = k - 1
while (r < n):
    if (t[l] == 0):
        s -= a[l]
    if (r + 1 < n and t[r + 1] == 0):
        s += a[r + 1]
    l += 1
    r += 1
    ans = max(ans, s)
print(ans)