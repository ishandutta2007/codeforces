from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint

for _ in range(int(input())):
    n = int(input())
    ans = [6, 10, 14]
    if n <= 30:
        print("NO")
    else:
        if n - 30 in ans:
            ans[2] += 1
            ans.append(n - 31)
        else:
            ans.append(n - 30)
        print("YES")
        print(*ans)