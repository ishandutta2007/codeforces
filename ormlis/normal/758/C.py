from sys import stdin


def get(n, m, k, x, y):
    if x > n or x < 1:
        return -1
    if n == 1:
        return k // m + (k % m >= y)
    kr = (n - 1) * 2 * m
    if x == 1 or x == n:
        res = k // kr
    else:
        res = k // kr * 2
    sot = k % kr
    if sot >= (x - 1) * m + y:
        res += 1
    if sot >= (2 * n - 1 - x) * m + y and x != n:
        res += 1
    return res

def solve():
    n, m, k, x, y = map(int, input().split())
    ans = [get(n, m, k, 2, 1), get(n, m, k, 1, 1), get(n, m, k, n-1, 1), get(n, m, k, n, m), get(n, m, k, 1, 1)]
    ans = list(filter(lambda x: x != -1, ans))
    print(max(ans), min(ans), get(n, m, k, x, y))


for i in range(1):
    solve()