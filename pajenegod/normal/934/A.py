import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

A.sort()
B.sort()

besta1 = -1000000000000000000000000000000000
for i in range(1,n):
    for j in range(m):
        besta1 = max(besta1,A[i]*B[j])
besta2 = -1000000000000000000000000000000000
for i in range(n-1):
    for j in range(m):
        besta2 = max(besta2,A[i]*B[j])
print min(besta1,besta2)