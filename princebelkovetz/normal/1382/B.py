from math import ceil
from sys import stdin, stdout, setrecursionlimit

for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    ind = -1
    for i in range(n):
        if a[i] != 1:
            ind = i
            break
    if ind == -1:
        if n % 2 == 1:
            print("First")
        else:
            print("Second")
    elif ind % 2 == 0:
        print("First")
    else:
        print("Second")