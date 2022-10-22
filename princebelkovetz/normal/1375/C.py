from sys import stdin, stdout, setrecursionlimit
from math import ceil
for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    if a[n - 1] > a[0]: print("YES")
    else: print("NO")