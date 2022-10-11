import sys
range = xrange
input = raw_input

n,k,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()

Asum = sum(A)
Alen = len(A)
besta = 0
for rem in range(min(m+1,len(A))):
    add = min(m-rem,k*Alen)
    besta = max(1.0*(Asum+add)/Alen,besta)

    Asum -= A[rem]
    Alen -= 1
print '%20.20f' % besta