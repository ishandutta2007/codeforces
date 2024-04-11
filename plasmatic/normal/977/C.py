from collections import *
import sys

input = lambda: sys.stdin.readline().strip()

orddict = OrderedDict
defdict = defaultdict
counter = Counter

def nextint(): return int(input())
def snexts(): return input().split(' ')
def snextint(): return map(int, snexts())
# def array(length, base=0): return [base] * length
# def matrix(length, width, base=0): return [[base] * width for _ in range(length)]

n, k = snextint()
lis = map(int, input().split())
dic = defaultdict(int)
lismin = 2000000000

for i in lis:
    lismin = min(lismin, i)
    dic[i] += 1

tups = sorted(dic.items())

curr = 0
corv = -1

if k == 0:
    if lismin > 1:
        print(lismin - 1)
    else:
        print(-1)
else:
    for kk, v in tups:
        curr += v

        if curr == k:
            corv = kk
            break
        elif curr > k:
            break
    
    print(corv)