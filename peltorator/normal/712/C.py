x, y = [int(i) for i in input().split()]
if x > y:
    t = x
    x = y
    y = t
a = [x, x, x]
ans = 0
while a[0] != y or a[1] != y or a[2] != y:
    a[0] = min(a[1] + a[2] - 1, y)
    a.sort()
    ans += 1
print(ans)