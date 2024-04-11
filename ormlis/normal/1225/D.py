def f(n):
    Ans = []
    d = 2
    while d * d <= n:
        if n % d == 0:
            Ans.append(d)
            n //= d
        else:
            d += 1
    if n > 1:
        Ans.append(n)
    return Ans


n, k = map(int, input().split())
arr = list(map(int, input().split()))

m = {}
c = 0
for i in arr:
    r = {}
    d = 2
    while d * d <= i:
        if i % d == 0:
            r[d] = (r.get(d, 0) + 1) % k
            i //= d
        else:
            d += 1
    if i > 1:
        r[i] = (r.get(i, 0) + 1) % k
    r = tuple(filter(lambda x: x[1], r.items()))
    r2 = tuple(map(lambda x: (x[0], k - x[1]), r))
    c += m.get(r2, 0)
    m[r] = m.get(r, 0) + 1
print(c)