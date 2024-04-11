import sys
xrange = range
input = raw_input
import math
from math import sqrt
import bisect

small = 10**5+1
big = 10**18+1

pos = []
f = pos.append
#pos.add(1)
j = 2
while True:
    #if sqrt(j).is_integer():
    #    j+=1
    #    continue
    j2 = j*j
    i = j*j2
    if i>=big:
        break
    #if int(i**0.5+0.5)**2==i:
    #    j+=1
    #    continue
    while i<big:
        f(i)
        i *= j2
    j += 1
pos2 = [p for p in pos if not sqrt(p).is_integer()]
pos2.sort()
prev = -1
pos = []
f = pos.append
for p in pos2:
    if p==prev:
        continue
    f(p)
    prev = p



q = int(input())
#inp = [int(x) for line in sys.stdin for x in line.split()]
#ii = 0
out = []
for line in sys.stdin:
    L,R = line.split()
    L = int(L)
    R = int(R)
    

    #ii+=2
    a = -1
    b = len(pos)
    
    
    while b-a>1:
        m = (a+b)//2
        if pos[m]<L:
            a=m
        else:
            b=m
    under = a
    #under = bisect.bisect_left(pos,L)
    #if under<len(pos) and pos[under]>=L:
    #    under -= 1
    
    a = -1
    b = len(pos)
    
    
    
    while b-a>1:
        m = (a+b)//2
        if pos[m]<=R:
            a = m
        else:
            b = m
    upper = a
    #upper = bisect.bisect_left(pos,R+1)-1
    Lupp = max(int(sqrt(L)-1),0)
    while Lupp*Lupp<L:
        Lupp+=1
    
    Rdown = int(sqrt(R))+1
    while Rdown*Rdown>R:
        Rdown-=1

    count = max(0,Rdown-Lupp+1)
    out.append(str(upper-under+count))
print('\n'.join(out))