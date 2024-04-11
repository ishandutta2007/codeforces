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
lis = [0] + list(map(int, input().split()))
dic = {}

for i in range(1, n + 1):
    if lis[i] in dic:
        dic[lis[i]] = min(dic[lis[i]], i)
    else:
        dic[lis[i]] = i

dp = [0] * (n + 1)
par = [-1] * (n + 1)

for i in range(1, n + 1):
    lastv = lis[i] - 1
    
    if lastv in dic and dic[lastv] < i:
        lastind = dic[lastv]

        dp[i] = dp[lastind] + 1
        par[i] = lastind
    
    dic[lis[i]] = i

# get best index

best = -100
bestind = -1

for i in range(1, n + 1):
    if dp[i] > best:
        best = dp[i]
        bestind = i

# backtrack

outputs = []

while bestind != -1:
    outputs.append(bestind)
    bestind = par[bestind]

print(best + 1)
print(' '.join(reversed(list(map(str, outputs)))))