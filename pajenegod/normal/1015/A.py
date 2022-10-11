import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
A = [False]*1000
for _ in range(n):
    l,r  = [int(x) for x in input().split()]
    for i in range(l,r+1):
        A[i]=True
X = [i for i in range(1,m+1) if not A[i]]
if len(X)==0:
    print 0
else:
    print len(X)
    print ' '.join(str(x) for x in X)