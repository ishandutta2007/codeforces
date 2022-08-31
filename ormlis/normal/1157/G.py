def check(a):
    n = len(a)
    m = len(a[0])
    if a[0][-1] == 1:
        flag = True
    else:
        flag = False
    ones = [1] * m
    zeros = [0] * m
    r = [0] * n
    c = [0] * m
    for i in range(1, n):
        if flag:
            if a[i] == ones:
                continue
            elif a[i] == zeros:
                r[i] ^= 1
            else:
                return None, None
        elif a[i] == ones:
            r[i] ^= 1
        elif a[i] == zeros:
            continue
        elif a[i] == sorted(a[i]):
            flag = True
        elif a[i] == sorted(a[i], reverse=True):
            flag = True
            r[i] ^= 1
        else:
            return None, None
    return r, c


def combine(a, b):
    return list(map(lambda x: x[0] ^ x[1], zip(a, b)))


def solve():
    n, m = map(int, input().split())
    a = [[0] * m for _ in range(n)]
    for i in range(n):
        a[i] = list(map(int, input().split()))
    for t in range(2):
        for r in range(m):
            acur = [[a[i][j] for j in range(m)] for i in range(n)]
            c1 = [0] * m
            for i in range(m):
                acur[0][i] ^= t
                if acur[0][i] == 1 and i <= r:
                    c1[i] ^= 1
                    for j in range(n):
                        acur[j][i] ^= 1
                elif acur[0][i] == 0 and i > r:
                    c1[i] ^= 1
                    for j in range(n):
                        acur[j][i] ^= 1
            r, c = check(acur)
            if r:
                print("YES")
                r[0] ^= t
                print(*r, sep='')
                print(*combine(c, c1), sep='')
                return
    print("NO")


for _ in range(1):
    solve()