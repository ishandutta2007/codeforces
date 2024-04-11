import math
from decimal import *
import sys
from fractions import Fraction

n=int(input())
x=[]
y=[]

for i in range(0,n):
    inp=list(map(int,input().split()))
    x.append(inp[0])
    y.append(inp[1])

if n==1:
    print(-1)
if n==2:
    if y[0] == y[1] or x[0] == x[1]:
        print(-1)
    else:
        print(abs(x[0]-x[1]) * abs(y[0]-y[1]))
if n>=3:

    ans=0
    for a in range(0,n):
        for i in range(0,n):
            if abs(x[a]-x[i]) * abs(y[a]-y[i]) != 0:
                ans = abs(x[a]-x[i]) * abs(y[a]-y[i])
    print(ans)