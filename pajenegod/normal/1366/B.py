import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    x = inp[ii] - 1; ii += 1
    m = inp[ii]; ii += 1
    
    L = inp[ii + 0: ii + 2 * m: 2]
    R = inp[ii + 1: ii + 2 * m: 2]
    ii += 2 * m
    L = [l - 1 for l in L]
    R = [r - 1 for r in R]

    ax = bx = x
    for j in range(m):
        l = L[j]
        r = R[j]
        if l <= ax <= r:
            ax = l
        if l <= bx <= r:
            bx = r
    print bx - ax + 1