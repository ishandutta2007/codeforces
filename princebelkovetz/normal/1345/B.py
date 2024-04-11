from sys import stdin, stdout, setrecursionlimit
input = stdin.readline
print = stdout.write
for _ in range(int(input())):
    n = int(input())
    cou = 0
    while n > 1:
        x = 1
        while ((x + 1) * (x) + ((x - 1) * (x)) // 2) <= n:
            x += 1
        n -= ((x - 1) * (x) + ((x - 1) * (x - 2)) // 2)
        cou += 1
    print(str(cou) + '\n')