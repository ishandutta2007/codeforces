import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]

    ans = 0

    x = min(A[2], B[1])
    A[2] -= x
    B[1] -= x

    ans += 2 * x

    x = min(A[2], B[2])
    A[2] -= x
    B[2] -= x

    x = min(A[1], B[1])
    A[1] -= x
    B[1] -= x

    x = min(A[0], B[2])
    A[0] -= x
    B[2] -= x
    
    x = min(A[1], B[2])
    A[1] -= x
    B[2] -= x
    ans -= 2 * x

    print ans