
import math
import sys

n = int(input())
ans=0
c=[]
for i in range(0,n):
    m=0
    l=list(map(int,input().split()))
    for j in l:
        if j==2 or j==0:
            m+=1
    if m==n-1:
        ans+=1
        c.append(i)
print(ans)
for j in c:
    print(j+1, end=" ")
if c!=[]: print()