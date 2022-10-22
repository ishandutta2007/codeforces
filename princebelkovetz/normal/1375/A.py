from sys import stdin, stdout, setrecursionlimit
from math import ceil
for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    if a[0] < 0:
        a[0] = -a[0]
    for i in range(1, n):
        if i % 2 == 1 and a[i] > 0:
            a[i] = -a[i]
        elif i % 2 == 0 and a[i] < 0:
            a[i] = -a[i]
    print(*a)