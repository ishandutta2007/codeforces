def solve():
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    k = b - a
    ans = k // 5
    k %= 5
    ans += k // 2
    k %= 2
    ans += k
    print(ans)


for _ in range(int(input())):
    solve()