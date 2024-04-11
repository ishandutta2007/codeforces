
import sys
range = xrange
input = raw_input


n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

besta = -1
best_ind = -1
for i in range(k):
    if  besta<A[i]*(n//A[i]):
        best_ind = i
        besta = A[i]*(n//A[i])
print best_ind+1,n//A[best_ind]