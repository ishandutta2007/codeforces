import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1

    A = inp[ii: ii + n]; ii += n
    P = [p - 1 for p in inp[ii: ii + m]]; ii += m

    P.sort()

    i = 0
    while i < m:
        j = i
        while j + 1 < m and P[j] + 1 == P[j + 1]:
            j += 1
        A[P[i]:P[j] + 2] = sorted(A[P[i]:P[j] + 2])
        i = j + 1

    if A == sorted(A):
        print 'YES'
    else:
        print 'NO'