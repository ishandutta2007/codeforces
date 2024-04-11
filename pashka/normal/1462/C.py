def solve():
    n = int(input())
    s = ""
    c = 9
    while n > c:
        if c == 0:
            print(-1)
            return
        s = str(c) + s
        n -= c
        c -= 1
    s = str(n) + s
    print(s)


n = int(input())
for i in range(n):
    solve()