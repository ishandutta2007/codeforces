import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    B = {}
    for i in range(n):
        a = A[i]
        if a in B:
            B[a] = -1
        else:
            B[a] = i

    for a in sorted(B):
        if B[a] != -1:
            print B[a] + 1
            break
    else:
        print -1