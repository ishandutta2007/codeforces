def solve():
    a, b, c = map(int, input().split())
    s = [1, 2, 4, 6, 5, 3, 7]
    ans = 0
    a, b, c = sorted([a, b, c], reverse=True)
    for i in s:
        d = bin(i)[2:].rjust(3, '0')
        a1 = b1 = c1 = 0
        if d[0] == "1":
            a1 += 1
        if d[1] == "1":
            b1 += 1
        if d[2] == "1":
            c1 += 1
        if a1 > a or b1 > b or c1 > c:
            continue
        a -= a1
        b -= b1
        c -= c1
        ans += 1
    print(ans)



for i in range(int(input())):
    solve()