import sys
range = xrange
input = raw_input

n = int(input())

A = [int(x) for x in input().split()]


counter = [0]*(n+10)
counter[0] = n

active = set()
occ = [0] * (10**5+100)

x = 1
for i,a in enumerate(A):
    
    o = occ[a]
    counter[o] -= 1
    occ[a] += 1
    counter[o+1] += 1

    if counter[o]==0:
        active.discard(o)
    if counter[o+1] == 1:
        active.add(o+1)

    
    if 0<len(active)<=2:
        y = min(active)
    
    if len(active)==1:
        if y == 1 or counter[y] == 1:
            x = i+1
    elif len(active)==2:
        if (counter[y]==1 and y==1) or (counter[y]>0 and counter[y+1] == 1):
            x = i+1
print x