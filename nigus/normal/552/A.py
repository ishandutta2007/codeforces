import math
import sys

n=int(input())
ans = 0
for i in range(0,n):
    inp=list(map(int,input().split()))
    x1=inp[0]
    y1=inp[1]
    x2=inp[2]
    y2=inp[3]
    X=x2-x1+1
    Y=y2-y1+1
    ans+=X*Y
print(ans)