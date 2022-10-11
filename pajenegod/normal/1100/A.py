import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

A = [int(x) for x in input().split()]

maxi = 0
before = sum(A)
for i in range(k):
    maxi = max(maxi,abs(before-sum(A[i::k])))
print maxi