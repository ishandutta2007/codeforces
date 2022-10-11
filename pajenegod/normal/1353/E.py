ord0 = b'0'[0]

qqq = int(input())
ans = []
for _ in range(qqq):
    n, k = [int(x) for x in input().split()]
    s = [c - ord0 for c in input().encode('ascii')]
    res = 10**9
    tot = sum(s)
    for rem in range(k):
        c = s[rem:n:k]
        m = len(c)
        cnt = sum(c)
        x0,x1,x2 = 0,0,0
        for x in c:
            if x == 0:
                x1, x2 = min(x0, x1) + 1, min(x0,x1,x2)
                #dp.append([dp[-1][0], min(dp[-1][0], dp[-1][1]) + 1, min(dp[-1])])
            else:
                x0,x1,x2 = x0 + 1, min(x0, x1), min(x0,x1,x2) + 1
                #dp.append([dp[-1][0] + 1, min(dp[-1][0], dp[-1][1]), min(dp[-1]) + 1])
        res = min(res, tot - cnt + min(x0,x1,x2))
    ans.append(res)
print("\n".join(str(x) for x in ans))