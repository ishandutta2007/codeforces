from sys import stdin, stdout, setrecursionlimit
from math import ceil
input = stdin.readline
# = map(int, input().split())
# a = [int(i) for i in input().split(]
for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    x = 0
    if b < a and d >= c:
        print(-1)
    elif b < a:
        x = a - b
        b += (c) * ceil(x / (c - d))
        print(b)
    else:
        print(b)