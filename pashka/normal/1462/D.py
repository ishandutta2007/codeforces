def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    for i in range(1, n + 1):
        s = sum(a[:i])
        c = 0
        for j in range(n):
            c += a[j]
            if c == s:
                c = 0
        if c == 0:
            print(n - sum(a) // s)
            return


n = int(input())
for i in range(n):
    solve()