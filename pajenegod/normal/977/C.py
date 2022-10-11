import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()

if k==0:
    if A[0]==1:
        print -1
    else:
        print 1
elif k<n and A[k-1]==A[k]:
    print -1
else:
    print A[k-1]