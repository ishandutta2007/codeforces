from sys import stdin, stdout, setrecursionlimit
input = stdin.readline

for _ in range (int(input())):
    n = int(input())
    a = sorted([int(i) for i in input().split()])
    cur = 1
    cou = 0
    for i in range(n):
        if a[i] <= cur + cou:
            cur += cou + 1
            cou = 0
        else: cou += 1

    print(cur)