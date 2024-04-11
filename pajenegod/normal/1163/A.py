import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

k = n - m

A = [False]*n
i = 0
while k and i<n:
    A[i] = True
    i += 2
    k -= 1

i = 1
while k and i<n:
    A[i] = True
    i += 2
    k -= 1

A.append(A[-1])
count = 0
for i in range(n):
    if A[i] and not A[i-1]:
        count += 1

if m == 0:
    print 1
else:
    print count