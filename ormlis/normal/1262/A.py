t = int(input())
for _ in range(t):
    n = int(input())
    rmin = 1000000000000000
    lmax = 0
    for i in range(n):
        l, r = map(int, input().split())
        lmax = max(l, lmax)
        rmin = min(r, rmin)
    print(max(lmax - rmin, 0))