
import math
import sys
from decimal import Decimal
inp=list(map(int,input().split()))
n=inp[0]
m=inp[1]
c=[]
for i in range(0,n):
    s=input()
    c.append([])
    for j in range(0,m):
        c[i].append(s[j])

ans=0

for i in range(0,n-1):
    for j in range(0,m-1):
        t=c[i][j]+c[i+1][j]+c[i+1][j+1]+c[i][j+1]
        if 'a' in t and 'f' in t and 'c' in t and 'e' in t:
            ans+=1
print(ans)