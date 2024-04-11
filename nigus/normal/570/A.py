
import math
import sys

x=list(map(int,input().split()))
n=x[0]
m=x[1]

W=[]
NW=[]

for i in range(0,n):
    NW.append(0)


for i in range(0,m):
    l=list(map(int,input().split()))
    k=max(l)
    for j in range(0,n):
        if l[j] == k:
            w=j
            break
    W.append(w)

for i in range(0,m):
    NW[W[i]]+=1

k=max(NW)

for i in range(0,n):
    if NW[i] == k:
        w=i+1
        break
print(w)