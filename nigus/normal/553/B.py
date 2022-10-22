import math
import sys

def fib(x):
    if x<1:
        return 0
    if x==1:
        return 1
    if x==2:
        return 2
    a=1
    b=2
    for i in range(0,x):
        c=a
        a=b
        b=c+b
    return b-a
    
    


inp=list(map(int,input().split()))

n=inp[0]
k=inp[1]
k2=k
n2=n
ans=[]
c=0
while n2>0:

    f1=fib(n2-1)
    f2=fib(n2-2)

    if n2==1:
        ans.append(1+c)
        break
    
    if k2<=f1:
        ans.append(1+c)
        n2-=1
        c+=1
    else:
        ans.append(2+c)
        ans.append(1+c)
        c+=2
        n2-=2
        k2=k2-f1
        


if n==1:
    ans=[1]
if n==2 and k==1:
    ans=[1,2]
if n==2 and k==2:
    ans=[2,1]



for i in range(0,n-1):
    print(str(ans[i]),end=" ")
print(str(ans[n-1]))