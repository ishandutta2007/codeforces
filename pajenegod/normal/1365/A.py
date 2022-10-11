import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1

    A = inp[ii: ii + n * m]; ii += n * m
    usedcol = [0]*m
    usedrow = [0]*n
    for y in range(n):
        for x in range(m):
            val = A[y*m + x]
            usedcol[x] |= val
            usedrow[y] |= val

    val = min(m - sum(usedcol),n - sum(usedrow))
    print 'Vivek' if val & 1 == 0 else 'Ashish'