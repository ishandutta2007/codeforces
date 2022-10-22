from sys import stdin, stdout, setrecursionlimit
from math import ceil
input = stdin.readline
# = map(int, input().split())
# a = [int(i) for i in input().split(]
for _ in range(int(input())):
    s = input()
    if '1' not in s or '2' not in s or '3' not in s:
        print(0)
        continue
    i1 = -1
    mn = 99999999
    for i in range(len(s) - 2):
        if s[i] != s[i + 1]:
            if i1 != -1 and s[i1] != s[i + 1]:
                mn = min(mn, i + 2 - i1)
                i1 = i
            else:
                i1 = i

    print(mn)