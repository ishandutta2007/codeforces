from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint
###
for _ in range(int(input())):
     n, k = map(int, input().split())
     print(sum(sorted([int(i) for i in input().split()], reverse=True)[:k + 1]))