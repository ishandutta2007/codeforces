import sys
from collections import defaultdict as di
input = raw_input
range = xrange

class segtree:
    def __init__(self,n):
        m = 1
        while m<n:m*=2
        self.n = n
        self.m = m
        self.data = [0]*(2*m)
        self.modified = []
    def set(self,ind,val):
        ind += self.m
        if val>self.data[ind]:
            self.modified.append(ind)
            while ind>0:
                self.data[ind] = val
                val = max(val,self.data[ind^1])
                ind //= 2
    def clean(self):
        while self.modified:
            ind = self.modified.pop()
            while ind>0:
                self.data[ind] = 0
                ind //= 2
    def maxi(self,l,r):
        l += self.m
        r += self.m
        val = 0
        while l<r:
            if l&1:
                val = max(val,self.data[l])
                l += 1
            if r&1:
                r -= 1
                val = max(val,self.data[r])
            l//=2
            r//=2
        return val

n = int(input())
A = [int(x) for x in input().split()]

same_val = di(list)

for l in range(n):
    asum = 0
    for r in range(l+1,n+1):
        asum += A[r-1]
        same_val[asum].append((l,r))

seg = segtree(n)
besta = 0
best_pairs = []
for pairs in same_val.values():
    seg.clean()
    for l,r in pairs:
        dp_val = seg.maxi(0,l)
        seg.set(r-1,dp_val+1)
    tmp = seg.data[1]
    if tmp>besta:
        besta = tmp
        best_pairs = pairs

DP = [0]*(n+1)
who = [-1]*(n+1)
who_const = [None]*(n+1)
for i in reversed(range(n)):
    DP[i] = DP[i+1]
    who_const[i] = who_const[i+1]
    while best_pairs and best_pairs[-1][0]==i:
        l,r = best_pairs.pop()
        if DP[r]+1>DP[i]:
            DP[i] = DP[r]+1
            who[i] = who_const[r]
            who_const[i] = (l,r)

maxDP = 0
maxind = 0
for i in range(n):
    if DP[i]>maxDP:
        maxDP = DP[i]
        maxind = i
out = []
pair = who_const[maxind]
while pair is not None:
    out.append(pair)
    l,r = pair
    pair = who[l]

print len(out)
print '\n'.join(str(x+1)+" "+str(y) for x,y in out)