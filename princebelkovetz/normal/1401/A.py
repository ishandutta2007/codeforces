from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint

for _ in range(int(input())):
    n, k = map(int, input().split())
    ans = 0
    if n < k:
        ans += k - n
        n = k
    if (n - k) % 2 == 1:
        ans += 1
    print(ans)