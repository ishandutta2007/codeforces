import sys
range = xrange
input = raw_input

X,d = [int(x) for x in input().split()]

A = []
start = 1
for i in range(10000):
    n=0
    while 2**(n+1)-1<=X and len(A)<=10**4:
        n+=1
        A.append(start)
    X = X-(2**n-1)
    start = start+d+1
if len(A)>10**4:
    print -1
else:
    print len(A)
    print ' '.join([str(x) for x in A])