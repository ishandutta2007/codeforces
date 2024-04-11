from sys import stdin, stdout, setrecursionlimit
from math import ceil
n = int(input())
s = input()
cntl = cntr = 0
for x in s:
    if x == 'L':
        cntl += 1
    else:
        cntr += 1
print(cntl + cntr + 1)