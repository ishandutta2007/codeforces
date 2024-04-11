
import math
import sys

n=int(input())
a=list(map(int,input().split()))
b=[]
for i in range(0,n):
    b.append(-a[i]*10000-i)
b.sort()
r=[]
for i in range(0,n):
    r.append(0)
for i in range(0,n):
    x=-b[i]
    j=x%10000
    k= round((x-(x%10000))/10000)
    if i==0:
        r[j]=1
    else:
        y=-b[i-1]
        k2= round((y-(y%10000))/10000)
        j2=y%10000
        if k2==k:
            r[j]=r[j2]
        else:
            r[j]=i+1
for i in range(0,n-1):
    print(str(r[i]),end=" " )
print(str(r[n-1]))