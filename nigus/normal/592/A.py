
import math
from decimal import *
import sys

S=set()
mw = 100
mb = 100
B=[]
for i in range(0,8):
    A=input()
    B.append(A)
    for j in range(0,8):
        k = A[j]
        if k == 'W' and j not in S:
            if i < mw:
                mw=i
            S.add(j)
        if k == 'B' and j not in S:
            S.add(j)

D=set()
for i in range(0,8):

    A = B[7-i]

    for j in range(0,8):
        k = A[j]
        if k == 'B' and j not in D:
            if i < mb:
                mb=i
            D.add(j)
        if k == 'W' and j not in D:
            D.add(j)

if mw <= mb:
    print('A')
else:
    print('B')