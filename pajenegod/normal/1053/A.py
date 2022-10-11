import sys
from collections import defaultdict as di
range = xrange
input = sys.stdin.readline

n,m,k = [int(x) for x in input().split()]

flip = False
if m<n:
    flip=True
    n,m=m,n


big = 10**5
P = [True]*big
P[0]=P[1]=False
for i in range(big):
    if P[i]:
        j = i*i
        while j<big:
            P[j]=False
            j+=i
P = [p for p in range(big) if P[p]]

N = n
M = m
K = k

factors = di(int)
factors[2]+=1

for p in P:
    while N%p==0:
        factors[p]+=1
        N//=p
if N>1:
    factors[N]+=1

for p in P:
    while M%p==0:
        factors[p]+=1
        M//=p
if M>1:
    factors[M]+=1

for p in P:
    while K%p==0:
        factors[p]-=1
        K//=p
if K>1:
    factors[K]-=1

if any(factors[p]<0 for p in factors):
    print 'NO'
    sys.exit()

facs = {1}
for p in factors:
    for _ in range(factors[p]):
        facs |= {p*f for f in facs if p*f<=n}
facs = sorted(facs)

i = -1
while i+1<len(facs) and facs[i+1]<=n:i+=1
if i==-1:
    print 'NO'
    sys.exit()

if ((2*n*m)//k)//facs[i] <= m:
    print 'YES'
    x = facs[i]
    y = ((2*n*m)//k)//x
    print 0,0
    if flip:
        x,y=y,x
    print x,0
    print 0,y
else:
    print 'NO'