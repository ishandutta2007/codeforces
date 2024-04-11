from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint
###
for _ in range(int(input())):
    n = int(input())
    c = False
    for i in range(3):
        if c:
            break
        for j in range(3):
            if (n - i * 5 - j * 7) % 3 == 0 and n - i * 5 - j * 7 >= 0:
                print((n - i * 5 - j * 7) // 3, i, j)
                c = True
                break
    if not c:
        print(-1)