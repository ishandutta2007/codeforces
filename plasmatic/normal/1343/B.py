import sys
input = sys.stdin.readline
for i in range(int(input())):
    n = int(input())
    if n % 4 != 0:
        print('NO')
    else:
        print('YES')
        inc = n // 2
        res = []
        dif = 0
        for i in range(inc):
            res.append(i * 2 + 2)
            dif += i * 2 + 2
        for i in range(inc - 1):
            res.append(i * 2 + 1)
            dif -= i * 2 + 1
        print(' '.join(map(str, res)), dif)