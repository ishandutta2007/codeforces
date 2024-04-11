import math
from decimal import *
import sys
from fractions import Fraction


s=input()
l=len(s)
s2=""
for i in range(0,l):
   if s[i]==';' or s[i]==',':
      s2+="# #"
   else:
      s2+=s[i]
sl=s2.split()
l=len(sl)

N="0123456789"
a=[]
b=[]
for i in range(0,l):
   w=sl[i]
   l2 = len(w)
   num=1
   if l2 != 0:
      if w[l2-1] == "#":
         w = w[:-1]
         l2=len(w)

   if l2 != 0:
      if w[0] == "#":
         w = w[1:]
         l2=len(w) 
   if l2==0:
      num=0
   for k in range(0,l2):
      if w[0] == '0' and l2>1:
         num=0
      if w[k] not in N:
         num=0
   if num==1:
      a.append(w)
   else:
      b.append(w)
la=len(a)
lb=len(b)

sa="\""
sb="\""
if la==0:
   sa="-"
else:
   for i in range(0,la-1):
      sa += a[i]+","
   sa += a[la-1]+"\""
print(sa)

if lb==0:
   sb="-"
else:
   for i in range(0,lb-1):
      sb += b[i]+","
   sb += b[lb-1]+"\""
print(sb)