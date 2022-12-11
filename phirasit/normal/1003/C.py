n, k = map(int, input().split())
a = list(map(int, input().split()))

lo, hi = 0, max(a)
while lo + 1e-10 < hi:
    mid = (lo + hi) / 2

    mn = 0
    s2 = 0
    s = 0
    for i in range(n):
        if i >= k:
            s2 += a[i-k] - mid
            mn = min(mn, s2)
        s += a[i] - mid
        if i+1 >= k and s >= mn:
            lo = mid
            break
    else:
        hi = mid

print ("%.10f" % (lo))