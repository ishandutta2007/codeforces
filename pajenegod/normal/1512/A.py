import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    i = A.index(min(A))
    j = A.index(max(A))

    if A.count(A[i]) == 1:
        print i + 1
    else:
        print j + 1