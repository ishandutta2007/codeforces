import sys
range = xrange
input = raw_input

n = int(input())

L = []
R = []
for _ in range(n):
    l,r = [int(x) for x in input().split()]
    L.append(l)
    R.append(r)

A = []
for i in range(n):
    x = 0
    li = L[i]
    ri = R[i]
    for j in range(n):
        x += i != j and (li <= L[j] < ri or L[j] <= li < R[j])
    A.append(x)

y = sum(A)
B = [i for i in range(n) if 2 * A[i] == y]
print len(B)
print ' '.join(str(i + 1) for i in B)