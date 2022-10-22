import math
from decimal import *
import sys
from fractions import Fraction

n=list(map(int,input().split()))
a=n[0]
b=n[1]
c=n[2]

ans = min([a+b+c,2*a+2*b,2*a+2*c,2*b+2*c])
print(ans)