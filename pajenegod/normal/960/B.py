import sys
range = xrange
input = raw_input

n,k1,k2 = [int(x) for x in input().split()]

A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

C = [abs(A[i]-B[i]) for i in range(n)]
k = k1+k2
while max(C)>0 and k>0:
    c = max(C)
    for j in range(n):
        if C[j]==c:
            break
    C[j]-=1
    k-=1
C = [c**2 for c in C]
if k>0:
    print sum(C)+(k%2)
else:
    print sum(C)