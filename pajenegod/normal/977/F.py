import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

coupl = [-1]*n
best = [-1]*n
occ = {}


for i in reversed(range(n)):
    if A[i]+1 in occ:
        j = occ[A[i]+1]
        coupl[i]=j
        best[i] = best[j]+1
    occ[A[i]]=i

besta = max(best)
for i in range(n):
    if best[i]==besta:
        break

seq = []
while i!=-1:
    seq.append(i)
    i=coupl[i]
print len(seq)
print ' '.join([str(x+1) for x in seq])