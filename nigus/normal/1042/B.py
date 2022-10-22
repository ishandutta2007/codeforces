n = int(input())
D = dict()
for _ in range(0, n):
    (x, s) = input().split()
    x = int(x)
    s = list(s)
    s.sort()
    s = "".join(s)
    if s not in D:
        D[s] = x
    D[s] = min(D[s], x)

ans = 128918291382
for mask in range(0, 2**len(D)):
    price = 0
    letters = []
    mask2 = mask
    for (s, x) in D.items():
        if mask2%2 == 1:
            letters += list(s)
            price += x
        mask2 //= 2
    if all(c in letters for c in "ABC"):
        ans = min(ans, price)
if ans < 11891121212:
    print(ans)
else:
    print(-1)