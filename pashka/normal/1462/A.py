def solve():
    n = int(input())
    a = [int(x) for x in input().split()]
    b = []
    l = 0
    r = n - 1
    for i in range(n):
        if i % 2 == 0:
            b.append(a[l])
            l += 1
        else:
            b.append(a[r])
            r -= 1
    print(*b)


n = int(input())
for i in range(n):
    solve()