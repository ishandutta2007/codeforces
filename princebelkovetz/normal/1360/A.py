from sys import stdin, stdout, setrecursionlimit
from math import ceil
for _ in range (int(input())):
    n, m = map(int, input().split())
    print(max((min(n, m) * 2), max(n, m)) ** 2)