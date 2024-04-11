from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n = int(input())
    summa = 0
    while n > 0:
        summa += 4 * (n // 2) + 4 * (n - 2) * (n // 2)
        n -= 2
    print(summa)