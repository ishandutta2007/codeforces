from sys import stdin, stdout, setrecursionlimit
from math import sqrt, ceil

def print(n):
    stdout.write (str(n) + '\n')
def m(n):
    for i in range(2, n + 1):
        if n % i == 0:
            return i
    return n

input = stdin.readline
for _ in range(int(input())):
    n, k = map(int, input().split())
    x = m(n)
    if x % 2 == 1:
        n += x
        n += 2 * (k - 1)
    else:
        n += k * x
    print(n)