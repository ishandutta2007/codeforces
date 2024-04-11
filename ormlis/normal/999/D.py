from sys import stdin


def solve():
    n, m = map(int, stdin.readline().split())
    a = list(map(int, stdin.readline().split()))
    ans = 0
    b = sorted(map(list, zip(map(lambda x: x % m, a), range(n))))
    j = 0
    need = n // m
    for i in range(m):
        e = j
        while e < len(b) and b[e][0] == i:
            e += 1
        if e - j >= need:
            for t in range(j + need, e):
                b.append(b[t])
            j = e
        else:
            for _ in range(need - (e - j)):
                w = b.pop()
                ans += (i - w[0]) % m
                a[w[1]] += (i - w[0]) % m
            j = e
    print(ans)
    print(*a)


solve()