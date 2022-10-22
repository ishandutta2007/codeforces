import math
import sys

inp=list(map(int,input().split()))
n=inp[0]
m=inp[1]

if (n*m)%2==0:
    print(round(n*m/2))
else:
    print(round((n*m - 1)/2))