from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint

for _ in range(int(input())):
    n = int(input())
    cur = 1
    ans = 0
    while True:
        need = cur * (cur + 1) // 2
        if need > n:
            break
        n -= need
        ans += 1
        cur = cur * 2 + 1
    print(ans)