
import math
import sys

n=int(input())
c=list(map(int,input().split()))
c.sort()
ans=0
for i in range(1,n):
    if c[i]<=c[i-1]:
        ans += c[i-1]+1-c[i]
        c[i] = c[i-1]+1
print(ans)