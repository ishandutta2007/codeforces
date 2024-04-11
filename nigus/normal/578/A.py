
import math
from decimal import *
import sys

inp=input().split()
a=int(inp[0])
b=int(inp[1])
getcontext().prec = 12
if b>a:
    print(-1)
else:
        s=a+b
        d=a-b
        c1=int((a+b)/b)
        if (a+b)%b==0:
            c1=round((a+b)/b)
        if c1%2==1:
            c1-=1
        c2=int((a-b)/b)

        if (a-b)%b==0:
            c2=round((a-b)/b)
        
        if c2%2==1:
            c2-=1
        if c1==0:
            c1=2
        if c2==0:
            if a==b:
                a2=b
            else:
                a2=437289472397
        else:
            a2=Decimal(d)/Decimal(c2)
        

        a1=Decimal(s)/Decimal(c1)
        ans=min(a1,a2)
        print(ans)