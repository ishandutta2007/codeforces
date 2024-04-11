import math
from decimal import *
import sys
from fractions import Fraction

T=int(input())

for j in range(0,T):

    n = int(input())

    t = 1
    lt = 0
    while 2*t <= n:
        t*=2
        lt+=1


    n2 = Fraction(n*(n+1))/Fraction(2)
    print(n2 - 2*(2*t-1))