import math
from decimal import *
import sys
from fractions import Fraction

def gcd(a,b):
    if b==0: return a
    return gcd(b,a%b)

inp=input().split()

t=int(inp[0])
w=int(inp[1])
b=int(inp[2])
                  
g=gcd(w,b)
l = Fraction(w,g)
l = l * Fraction(b)


m=Fraction((t-t%l),l)
#
#if t%l==0:
  #  m=round(t/l)
#else:
  #  m=int(t/l)

m+=1
mi = min(w,b)

m *= mi

if mi-(t%l)-1>0:
    m = m - mi + (t%l) +1
m -= 1
g2 = gcd(m,t)

ans1 = Fraction(m,g2)
ans2 = Fraction(t,g2)

print(str(ans1) + "/" + str(ans2))