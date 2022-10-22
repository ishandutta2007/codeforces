
import math
from decimal import Decimal
import sys

def rek(a,b,n):
    
    if a==n and b==n:
        return 1
    if a==n:
        return 1+rek(a,b+1,n)
    if b==n:
        return 1+rek(a+1,b,n)
    return 1+rek(a+1,b,n)+rek(a,b+1,n)
    
print(2000)
for i in range(1,1001):
    print(str(i) + " 1 " + str(i) + " 2")
for i in range(1,1001):
    print(str(1001-i) + " 1 " + str(1001-i) + " 2")