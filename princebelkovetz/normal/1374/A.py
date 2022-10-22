from sys import stdin, stdout, setrecursionlimit
from math import ceil
for i in range(int(input())):
    x, y, n = map(int, input().split())
    ok = n % x
    ok = ok + x - y
    ok %= x
    print(n - ok)