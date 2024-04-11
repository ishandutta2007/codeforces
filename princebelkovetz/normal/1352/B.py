from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n, k = map(int, input().split())
    if k > n or (n % 2 == 1 and k % 2 == 0) or (k % 2 == 1 and n % 2 == 0 and k * 2 > n):
        print('NO')
    else:
        a = []
        if n % 2 == k % 2:
            for i in range(k - 1):
                a.append(1)
                n -= 1
            a.append(n)
        elif n % 2 == 0:
            for i in range(k - 1):
                a.append(2)
                n -= 2
            a.append(n)
        print('YES')
        print(*a)