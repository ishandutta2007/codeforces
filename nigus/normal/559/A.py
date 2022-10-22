
import math
import sys


inp=list(map(int,input().split()))

s1=inp[0]
s2=inp[1]
s3=inp[2]
s4=inp[3]
s5=inp[4]
s6=inp[5]

a=min(s6,s2)
b=s1+a
c=max(s6,s2)-a

if a==s6:
    d=s3
else:
    d=s5

ans=0

ans+= 2*a*s1+a+a*a-a

ans+= 2*b*c

ans+= 2*d*s4+d+d*d-d

print(ans)