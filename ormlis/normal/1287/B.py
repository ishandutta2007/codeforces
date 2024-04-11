from sys import stdin


def get1(a, b):
    if a == b:
        return a
    if a == "S":
        if b == "E":
            return "T"
        return "E"
    if a == "E":
        if b == "S":
            return "T"
        return "S"
    if b == "S":
        return "E"
    return "S"


def get(a, b):
    return ''.join(map(lambda x: get1(*x), zip(a, b)))


def solve():
    n, k = map(int, stdin.readline().split())
    ans = 0
    a = list(map(str.strip, stdin.readlines()))
    b = set(a)
    for i in range(n):
        for j in range(i + 1, n):
            if get(a[i], a[j]) in b:
                ans += 1
    print(ans // 3)


for _ in range(1):
    solve()