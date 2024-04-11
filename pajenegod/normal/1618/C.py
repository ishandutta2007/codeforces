import sys
from math import gcd

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    a0 = 0
    a1 = 0
    for a in A[0::2]:
        a0 = gcd(a0, a)
    for a in A[1::2]:
        a1 = gcd(a1, a)


    for a in A[0::2]:
        if a % a1 == 0:
            break
    else:
        print(a1)
        continue
    
    for a in A[1::2]:
        if a % a0 == 0:
            break
    else:
        print(a0)
        continue
    print(0)