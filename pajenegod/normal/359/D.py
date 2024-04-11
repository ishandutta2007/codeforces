import sys
range = xrange
input = raw_input
from future_builtins import ascii, filter, hex, map, oct, zip

n = int(input())

A = [int(x) for x in input().split()]

explored = [0]*n
intervals = []
for i in range(n):
    if explored[i]:continue
    
    a = A[i]
    l = i
    while l>0 and A[l-1]%a==0:
        l -= 1

    r = i
    while r+1<n and A[r+1]%a==0:
        r += 1
    
    for i in range(l,r+1):
        if A[i]==a:
            explored[i] = 1
    intervals.append((l,r))

besta = max(r-l for l,r in intervals)
winners = set(l for l,r in intervals if r-l == besta)

print len(winners),besta

print ' '.join(str(l+1) for l in sorted(winners))