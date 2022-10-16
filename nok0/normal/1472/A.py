def solve():
    w, h, n = map(int, input().split())
    k, i = 1, 0
    while w % 2 == 0:
        w >>= 1
        k += pow(2, i)
        i += 1
    u = 1
    i = 0
    while h % 2 == 0:
        h >>= 1
        u += pow(2, i)
        i += 1
    k *= u
    if k >= n:
        print("YES")
    else:
        print("NO")


t = int(input())
for i in range(t):
    solve()