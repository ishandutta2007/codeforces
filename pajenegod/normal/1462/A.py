import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    B = [int(x) for x in input().split()]

    mid = n + 1 >> 1
    Aodd = B[:mid]
    Aeven = B[mid:][::-1]

    A = [0] * n
    A[::2] = Aodd
    A[1::2] = Aeven

    print ' '.join(str(a) for a in A)