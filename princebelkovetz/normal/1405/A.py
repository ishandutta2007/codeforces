from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    for i in range(n - 1, -1, -1):
        print(a[i], end=" ")
    print()