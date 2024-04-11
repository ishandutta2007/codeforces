from sys import stdin, stdout, setrecursionlimit
from math import ceil
for _ in range (int(input())):
    s = input()
    if '1' in s and '0' in s:
        print("01" * len(s))
    else:
        print(s)