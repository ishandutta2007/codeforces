n = int(input())


def solve_test():
    # 0, 2, 5, 5, 4, 8
    # 0, 2, 2, 2, 1, 2
    # c = [1, 1, 4]
    # 0, 0, 0, 2, 1, 2
    # 1, 0, 0, 2, 1, 2
    # 0 -> 1
    # 1 -> 2
    # 2 -> 0
    n = int(input())
    a = [int(x) for x in input().split()]
    c = [0, 0, 0]
    for x in a:
        y = x % 3
        c[y] += 1
    res = 0
    while max(c) != n // 3:
        i = c.index(max(c))
        d = c[i] - n // 3
        res += d
        c[i] -= d
        c[(i + 1) % 3] += d
    print(res)


for i in range(n):
    solve_test();