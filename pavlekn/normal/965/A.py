k, n, s, p = map(int, input().split())
l = 0
r = 10 ** 9
while (r - l != 1):
    m = (l + r) // 2
    if ((p * m // k) * s >= n):
        r = m
    else:
        l = m
print(r)