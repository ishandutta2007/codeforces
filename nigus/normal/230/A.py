import math
import sys

inp=list(map(int,input().split()))
s=inp[0]
n=inp[1]
x=[]
y=[]
mark=[]

for i in range(0,n):
    inp=list(map(int,input().split()))
    x.append(inp[0])
    y.append(inp[1])
    mark.append(0)


x2=[]
y2=[]

for i in range(0,n):
    mi = 999999999999
    k=0
    for j in range(0,n):
        if x[j] < mi and mark[j] == 0:
            mi = x[j]
            k=j
    mark[k] = 1
    x2.append(mi)
    y2.append(y[k])

fail = 0
for i in range(0,n):
    
    if s > x2[i]:
        s+=y2[i]
    else:
        fail=1
if fail == 0:
    print("YES")
else:
    print("NO")