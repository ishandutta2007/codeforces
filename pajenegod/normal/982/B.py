import sys
import heapq
range = xrange
input = raw_input

n = int(input())
# 1<=w<=10**9, distinct
W = [int(x) for x in input().split()]
A = [c=='1' for c in input()]

mapp = {}
for i in range(n):
    mapp[W[i]]=i

big = 10**10
emp = W
heapq.heapify(W)

picked = []

out = []
for a in A:
    if a:
        val = heapq.heappop(picked)
        out.append(big-val)
        
    else:
        val = heapq.heappop(emp)
        out.append(val)
        heapq.heappush(picked,big-val)

print ' '.join([str(mapp[x]+1) for x in out])