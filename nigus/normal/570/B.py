
import math
import sys

x=list(map(int,input().split()))
n=x[0]
m=x[1]

if m>int(n/2):
    a=m-1
else:
    a=m+1
if n==1 and m==1:
    a=1
print(a)