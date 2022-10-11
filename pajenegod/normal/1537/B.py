import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n,m,i,j = inp[ii: ii + 4]; ii += 4

    i -= 1
    j -= 1

    maxdist = 0.0
    sol = (0,0,0,0)
    for i1,j1 in (0,0), (0,m-1), (n-1,m-1), (n-1,0):
        for i2,j2 in (0,0), (0,m-1), (n-1,m-1), (n-1,0):
            dist = 0.0 + abs(i - i1) + abs(i1 - i2) + abs(i2 - i) +\
                   abs(j - j1) + abs(j1 - j2) + abs(j2 - j)
            
            if dist > maxdist:
                sol = (i1,j1,i2,j2)
                maxdist = dist
    print ' '.join(str(x + 1) for x in sol)