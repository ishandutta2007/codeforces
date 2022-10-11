from __future__ import division
import sys
range = xrange
input = sys.stdin.readline

sy,a,b = [int(x) for x in input().split()]

n = int(input())

inp = [int(x) for line in sys.stdin for x in line.split()]
ii = 0

L = []
R = []
for _ in range(n):
    l = inp[ii]
    r = inp[ii+1]
    ii+=2
    L.append(l)
    R.append(r)

Lsum = [0]
for l in L:
    Lsum.append(Lsum[-1]+l)
Rsum = [0]
for r in R:
    Rsum.append(Rsum[-1]+r)

out = []
q = inp[ii]
ii+=1
for _ in range(q):
    px = inp[ii]
    py = inp[ii+1]
    ii+=2

    shade = 0
    

    # L' = px + (l-px)/py*(py-sy)
    # R' = px + (l-px)/py*(py-sy)
    
    A = 0
    B = len(L)
    while A<B:
        M = (A+B)//2
        l = L[M]
        l = px + (l-px)/py*(py-sy)
        if l<a:
            A = M+1
        else:
            B = M
    ind1 = A

    if ind1==n:
        lista = [ind1-1]
    else:
        A = ind1-1
        B = len(R)-1
        while A<B:
            M = (A+B+1)//2
            r = R[M]
            r = px + (r-px)/py*(py-sy)
            if b<r:
                B = M-1
            else:
                A = M
        ind2 = A

        if ind2==ind1-1:
            lista = [ind1-2,ind1-1,ind1,ind1+1]
        else:
            
            l = Lsum[ind2+1]-Lsum[ind1]
            r = Rsum[ind2+1]-Rsum[ind1]
            
            l = (l)/py*(py-sy)
            r = (r)/py*(py-sy)

            shade += r-l

            lista = [ind1-1,ind2+1]

    
    for i in lista:
        if i<0 or i>=n:
            continue
        l = L[i]
        r = R[i]
        l = px + (l-px)/py*(py-sy)
        r = px + (r-px)/py*(py-sy)

        if l<=a:
            l = a
        if b<=r:
            r = b
        shade += max(r-l,0)
    out.append('%.10f'%(shade))
print '\n'.join(out)