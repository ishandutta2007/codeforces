n, m, k = map(int, input().split())
if (k < n):
    print(k + 1, 1)
else:
    k -= n
    k2 = k // (m - 1)
    k1 = k % (2 * m - 2)
    if (k1 < m - 1):
        print(n - k2, k1 + 2)
    else:
        print(n - k2, (2 * m - 3 - k1) + 2)