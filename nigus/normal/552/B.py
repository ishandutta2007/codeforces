import math
import sys

n=int(input())
s=str(n)
l=len(s)



k=1
ans=0
for i in range(0,l-1):
    ans+=9*k*(i+1)
    k*=10
m=n-k


ans+=(m+1)*l


if l==1:
    ans=n
print(ans)