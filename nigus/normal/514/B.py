
import math
import sys
#+

def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

inp=list(map(int,input().split()))
n=inp[0]
x0=inp[1]
y0=inp[2]
x=[]
y=[]
for i in range(0,n):
    m=list(map(int,input().split()))
    x.append(m[0]-x0)
    y.append(m[1]-y0)

S=set()
ans=0
yn=0
xn=0
for i in range(0,n):

    if x[i] < 0:
        a=-x[i]
        b=-y[i]
    else:
        a=x[i]
        b=y[i]
    if a!=0 and b!=0:
        g=gcd(abs(a),abs(b))
        a=round(a/g)
        b=round(b/g)

        if a*1000000+b not in S:
            ans+=1
            S.add(a*1000000+b)
    
    if a==0:
        if xn==0:
            xn+=1
            ans+=1
    if b==0:
        if yn==0:
            yn+=1
            ans+=1
print(ans)