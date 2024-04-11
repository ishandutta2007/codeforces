from collections import *
import sys

input = lambda: sys.stdin.readline().strip()

orddict = OrderedDict
defdict = defaultdict
counter = Counter

def nextint(): return int(input())
def snexts(): return input().split(' ')
def snextint(): return map(int, snexts())

mv = 50
n = nextint()
lis = map(int, input().split())
powers = [[] for _ in range(mv)]

for i in lis:
    amt = 0

    ti = i
    while ti % 3 == 0:
        amt += 1
        ti //= 3
    
    powers[amt].append(i)

final = []
for i in range(mv - 1, -1, -1):
    final.extend(sorted(powers[i]))

print(' '.join(map(str, final)))