import math
import sys

def test(d):
    if d==1:
        return 1
    if d%w==0:
        k=round(d/w)
        return test(k)
    if (d-1)%w==0:
        k=round((d-1)/w)
        return test(k)
    if (d+1)%w==0:
        k=round((d+1)/w)
        return test(k)
    return 0

    


inp=list(map(int,input().split()))

w=inp[0]
m=inp[1]

a=1



for i in range(0,100):
    if a>m:
        d=a-m
        break
    a*=w
ans=test(d)
if ans==1:
    print("YES")
else:
    print("NO")