import math
import sys

n=int(input())
s=input()
d=dict()
alfa="abcdefghijklmnopqrstuvwxyz"
for i in alfa:
    d[i]=0
ans=0
for i in s:
    if i==i.lower():
        d[i]+=1
    else:
        if d[i.lower()]==0:
            ans+=1
        else:
            d[i.lower()]-=1
print(ans)