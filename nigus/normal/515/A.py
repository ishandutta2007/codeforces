import math
import sys


n=list(map(int,input().split()))
a=n[0]
b=n[1]
s=n[2]

if s >= abs(a)+abs(b) and s%2 == (abs(a)+abs(b))%2:
    print("Yes")
else:
    print("No")