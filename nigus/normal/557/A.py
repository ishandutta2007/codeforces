import math
import sys

n=int(input())

inp=list(map(int,input().split()))

m1=inp[0]
M1=inp[1]

inp=list(map(int,input().split()))

m2=inp[0]
M2=inp[1]

inp=list(map(int,input().split()))

m3=inp[0]
M3=inp[1]
    
ans=[]

rest=n-m2-m3

ans=[rest,m2,m3]

rest=n-M1-m3

if rest>=m2 and rest<=M2:
    ans=[M1,rest,m3]

rest=n-M1-M2

if rest>=m3 and rest<=M3:
    ans=[M1,M2,rest]

print(str(ans[0]) + " " + str(ans[1]) + " " + str(ans[2]))