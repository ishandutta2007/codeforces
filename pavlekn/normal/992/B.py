from math import gcd
l, r, x, y = map(int, input().split())
a = []
if (y % x != 0):
    print(0)
else:
    y = y // x
    for i in range(1, int(y ** 0.5) + 1):
        if (y % i == 0 and i != y // i):
            a.append([i, y // i])
            a.append([y // i, i])
        elif (y % i == 0):
            a.append([i, i])
    ans = 0
    for i in range(len(a)):
        if (gcd(a[i][0], a[i][1]) == 1 and l <= x * a[i][0] <= r and l <= x * a[i][1] <= r):
            ans += 1
    print(ans)