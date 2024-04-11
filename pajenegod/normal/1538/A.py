import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    amin = min(A)
    amax = max(A)

    imin = A.index(amin) + 1
    imax = A.index(amax) + 1

    iminr = n - imin + 1
    imaxr = n - imax + 1

    print min(max(imin, imax), max(iminr, imaxr), imin + imaxr, iminr + imax)