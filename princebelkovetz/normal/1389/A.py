from math import ceil
from sys import stdin, stdout, setrecursionlimit
from random import randint
def gcd(a, b):
    if b == 0: return a
    return gcd(b, a % b)
for _ in range(int(input())):
    l, r = map(int, input().split())
    if (l * 2 * l) // gcd(l, l * 2) <= r and l * 2 <= r:
        print(l, l * 2)
    else:
        print("-1 -1")