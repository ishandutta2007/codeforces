import math
from decimal import *
import sys
from fractions import Fraction

M=list(map(int,input().split()))
W=list(map(int,input().split()))
H=list(map(int,input().split()))
X=[500,1000,1500,2000,2500]

ans = H[0]*100-H[1]*50

for i in range(0,5):
   ans += int(max(0.3 * X[i] , (250 - M[i]) * (X[i]/250) - 50*W[i]))
print(ans)