from math import ceil
from sys import stdin, stdout, setrecursionlimit

for _ in range(int(input())):
    n = int(input())
    cur1 = 3
    cur2 = 4
    while True:
        if n % cur1 == 0:
            print(n // cur1)
            break
        cur1 += cur2
        cur2 *= 2