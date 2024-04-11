from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint

for _ in range(int(input())):
    r, g, b, w = map(int, input().split())
    cnt = r % 2 + g % 2 + b % 2 + w % 2
    if cnt <= 1:
        print("Yes")
    elif r > 0 and g > 0 and b > 0:
        cnt = 4 - r % 2 - g % 2 - b % 2 - w % 2
        print("Yes" if cnt <= 1 else "No")
    else:
        print("No")