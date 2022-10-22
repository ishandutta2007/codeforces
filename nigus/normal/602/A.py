import math
from decimal import *
import sys
from fractions import Fraction


inp=input().split()
n=int(inp[0])
bx=int(inp[1])
X=list(map(int,input().split()))
    
inp=input().split()
m=int(inp[0])
by=int(inp[1])
Y=list(map(int,input().split()))

x=0
t=1
for i in range(0,n):
   x += X[n-i-1]*t
   t *= bx

y=0
t=1
for i in range(0,m):
   y += Y[m-i-1]*t
   t *= by

if x<y:
    print("<")
if x==y:
    print("=")
if x>y:
    print(">")