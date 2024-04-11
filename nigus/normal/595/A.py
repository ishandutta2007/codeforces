import math
from decimal import *
import sys
from fractions import Fraction

inp=input().split()
n=int(inp[0])
m=int(inp[1])
ans=0
for i in range(0,n):
    row = list(map(int,input().split()))
    for j in range(0,m):
        if row[2*j] == 1 or row[2*j+1] == 1:
            ans+=1
print(ans)