from sys import stdin, stdout, setrecursionlimit
from math import ceil
for i in range(int(input())):
    a, b, c = map(int, input().split())
    if c <= a:
        print(-1, end=" ")
    else:
        print(1, end=" ")
    if b * a <= c:
        print(-1)
    else:
        print(b)