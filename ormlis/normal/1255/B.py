def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    d = []
    if m != n or n == 2:
        return print(-1)
    print(sum(a)*2)
    for i in range(n):
        print(i + 1, (i + 1) % n + 1)


for _ in range(int(input())):
    solve()