from math import ceil
from sys import stdin, stdout, setrecursionlimit

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    ok = ['b', 'c', 'd']
    cur = 0
    ans = []
    for i in range(n + 1):
        ans.append('')
    ans[0] = 'a' * 200
    for i in range(n):
        for j in range(3):
            if ok[j] != ans[i][a[i]]:
                cur = j
                break
        ans[i + 1] = ans[i][:a[i]] + ok[cur] * (200 - a[i])
        cur += 1
    for i in range(n + 1):
        print(ans[i])