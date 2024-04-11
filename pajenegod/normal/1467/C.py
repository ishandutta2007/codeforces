import sys
range = xrange
input = raw_input

a,b,c = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

A.sort()
B.sort()
C.sort()

cost = min(A[0] + B[0], A[0] + C[0], B[0] + C[0])
cost = min(cost, sum(A))
cost = min(cost, sum(B))
cost = min(cost, sum(C))

print sum(A) + sum(B) + sum(C) - 2 * cost