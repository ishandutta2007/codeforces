import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    A = inp[ii: ii + n * m]; ii += n * m

    B = [0] * (n * m)
    for y in range(n):
        for x in range(m):
            val = 4 - (x == 0 or x == m - 1) - (y == 0 or y == n - 1)
            B[y * m + x] = val
    if any(A[i] > B[i] for i in range(n * m)):
        print 'No'
    else:
        print 'Yes'
        for y in range(n):
            print ' '.join(str(x) for x in B[y * m : y * m + m])