import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

B = A[:]
for i in range(1,n-1):
    if B[i-1]==1 and B[i]==0:
        B[i+1]=0

print sum(A)-sum(B)