
import math
import sys

inp=list(map(int,input().split()))
k=inp[0]
n=inp[1]
w=inp[2]

m=k*(round((w*w+w)/2))
if m-n < 0:
    print(0)
else:  
    print(m-n)