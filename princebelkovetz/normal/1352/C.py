from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n, k = map(int, input().split())
    x = k % (n - 1)
    if x == 0: x-= 1
    y = k // (n - 1)
    print(n * y + x)