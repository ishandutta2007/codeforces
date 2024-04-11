from sys import stdin, stdout, setrecursionlimit
from random import randint
import os
testcases = int(input())
for temp in range(testcases):
    n, k = map(int, input().split())
    for i in range(n):
        if i % 3 == 0:
            print('a', end="")
        elif i % 3 == 1:
            print('b', end="")
        else:
            print('c', end="")
    print()