
import math
import sys

s=input()
k=int(input())
l=len(s)
if l%k==0:
    d=round(l/k)
    fail=0
    for i in range(0,k):
        for j in range(0,d):
            if s[d*i+j] != s[d*i+d-j-1]:
                fail=1
    if fail==1:
        print("NO")
    else:
        print("YES")
else:
    print("NO")