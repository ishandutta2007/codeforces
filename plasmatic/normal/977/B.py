from collections import *
import sys

input = lambda: sys.stdin.readline().strip()

orddict = OrderedDict
defdict = defaultdict
counter = Counter

def nextint(): return int(input())
def snexts(): return input().split(' ')
def snextint(): return map(int, snexts())

n = nextint()
s = input()
grams = defaultdict(int)

for i in range(n - 1):
    grams[s[i] + s[i + 1]] += 1

mv = -10
gram = ''

for k, v in grams.items():
    if v > mv:
        mv = v
        gram = k

print(gram)