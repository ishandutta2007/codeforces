from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint
 
for _ in range(int(input())):
    n = int(input())
    s = input()
    cnt = 0
    if n % 2 == 1:
        for i in range(0, n, 2):
            if int(s[i]) % 2 == 1:
                cnt += 1
        print(1 if cnt > 0 else 2)
    else:
        for i in range(1, n, 2):
            if int(s[i]) % 2 == 0:
                cnt += 1
        print(2 if cnt > 0 else 1)