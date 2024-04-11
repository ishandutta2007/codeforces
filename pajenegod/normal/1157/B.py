import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input()]

mapper = [0] + [int(x) for x in input().split()]

i = 0
while i<n and A[i]>=mapper[A[i]]: i += 1

l = i
while i<n and A[i]<=mapper[A[i]]: i += 1
r = i

for i in range(l,r):
    A[i] = mapper[A[i]]

print ''.join(str(x) for x in A)