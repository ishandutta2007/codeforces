from sys import stdin, stdout, setrecursionlimit
from math import ceil
for i in range(int(input())):
    n = int(input())
    ans = 0
    while n % 6 == 0:
        n /= 6
        ans += 1
    while n % 3 == 0:
        ans += 2
        n /= 3
    if n == 1:
        print(ans)
    else:
        print(-1)