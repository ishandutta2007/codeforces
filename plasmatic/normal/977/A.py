from collections import *
import sys

input = lambda: sys.stdin.readline().strip()

orddict = OrderedDict
defdict = defaultdict
counter = Counter

def nextint(): return int(input())
def snexts(): return input().split(' ')
def snextint(): return map(int, snexts())

n, k = snextint()

for i in range(k):
    if n % 10: # not 0
        n -= 1
    else:
        n /= 10
        n = int(n)

print(n)