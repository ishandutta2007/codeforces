import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    sum1 = sum(A[0::2])
    sum2 = sum(A[1::2])

    B = [1] * n

    if sum1 >= sum2:
        B[0::2] = A[0::2]
    else:
        B[1::2] = A[1::2]

    print ' '.join(str(x) for x in B)