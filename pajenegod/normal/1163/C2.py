from math import gcd

n = int(input())
P = [[int(x) for x in input().split()] for _ in range(n)]

L = []
def addLine(x,y,dx,dy):
    if dx < 0:
        dx *= -1
        dy *= -1
    elif dx == 0:
        if dy < 0:
            dy *= -1
    g = gcd(dx,dy)
    dx //= g
    dy //= g

    if dx:
        k = x//dx
    else:
        k = y//dy
    x -= k*dx
    y -= k*dy
    L.append((x,y,dx,dy))


for i in range(n):
    for j in range(i+1,n):
        xi,yi = P[i]
        xj,yj = P[j]
        dx,dy = xi-xj,yi-yj
        addLine(xi,yi,dx,dy)

from collections import defaultdict as dd, deque

L = list(set(L))
res = 0

C = dd(int)
for x,y,dx,dy in L:
    C[dx,dy] += 1

ss = sum(C.values())

for x in C.values():
    res += (ss-x)*x

#for i in range(len(L)):
#    for j in range(i+1, len(L)):
#        x1,y1,dx1,dy1 = L[i]
#        x2,y2,dx2,dy2 = L[j]
#        if dx1 != dx2 or dy1 != dy2:
#            #print(L[i])
#            #print(L[j])
#            #print('---')
#            res += 1

print(res//2)