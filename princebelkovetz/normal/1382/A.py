from math import ceil
from sys import stdin, stdout, setrecursionlimit

for _ in range(int(input())):
    n, m = map(int, input().split())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]
    c = True
    for x in a:
        if x in b:
            print("YES")
            print(1, x)
            c = False
            break
    if c:
        print("NO")