import math
import sys

def fib(n,m):
    if n==0:
        return 0
    if n==1 or n==2:
        return 1%m
    b=n.bit_length()-1
    
    X=1
    Y=0
    Z=1
    k=n
    while b>=0:
        x=1
        y=1
        z=0
        t=1
        for i in range(0,b):
            x1=x
            y1=y
            x=(x1*x1+y1*y1)%m
            y=(x1*y1+y1*z)%m
            z=(y1*y1+z*z)%m
            t*=2

        Y2=Y
        X=(X*x+Y*y)%m
        Y=(x*Y+y*Z)%m
        Z=(y*Y2+z*Z)%m

        k=k-t
        b=k.bit_length()-1
    return Y
    
    

def two(n,m):

    if n==0:
        return 1%m
    if n==1:
        return 2%m
    T=1
    b=n.bit_length()-1
    k=n
    while b>=0:
        t2=1
        t1=2
        for i in range(0,b):
            t2*=2
            t1=(t1*t1)%m
        k=k-t2
        b=k.bit_length()-1
        T*=t1
        T=T%m
    return T

        

inp=list(map(int,input().split()))
n=inp[0]
k=inp[1]
l=inp[2]
m=inp[3]

if k>=2**l:
    print(0)
else:

    t=1
    ans=1
    for i in range(0,l):
        b=(k-k%t)%(2*t)
        t*=2
        if b==0:
            ans*=fib(n+2,m)
            ans=ans%m
        else:
            ans*=two(n,m)-fib(n+2,m)
            ans=ans%m
    
    print(ans%m)