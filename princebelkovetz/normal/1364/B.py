from sys import stdin, stdout, setrecursionlimit
for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    ok = []
    for i in range(1, n - 1):
        if a[i - 1] < a[i] < a[i + 1] or a[i - 1] > a[i] > a[i + 1]:
            ok.append(i)
    print(n - len(ok))
    curok = 0
    for i in range(n):
        if curok < len(ok) and i == ok[curok]:
            curok += 1
        else:
            print(a[i], end = " ")
    print()