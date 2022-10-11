import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

bit = 2**30
while bit:
    B = []
    for i in range(n):
        if A[i] & bit:
            B.append(i)

    if len(B) == 1:
        print ' '.join(str(x) for x in [A[B[0]]] + A[:B[0]] + A[B[0] + 1:])
        sys.exit()
    bit >>= 1
print ' '.join(str(x) for x in A)