from sys import stdin


def solve():
    n, x, y = map(int, stdin.readline().split())
    s = x + y
    t = min(max(s - n, 0), n-1)
    g = min(s - 1, n)
    k = max(g - y, 0)
    k2 = max(g - x, 0)
    print(t + 1, k + k2 + min(x - k, y - k2))


for i in range(int(stdin.readline())):
    solve()