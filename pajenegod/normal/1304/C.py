import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1

    T = inp[ii + 0: ii + n * 3: 3]
    L = inp[ii + 1: ii + n * 3: 3]
    R = inp[ii + 2: ii + n * 3: 3]
    ii += 3 * n

    minT = m
    maxT = m
    lastT = 0
    for i in range(n):
        t = T[i]
        l = L[i]
        r = R[i]
        maxT = min(maxT + t - lastT, r)
        minT = max(minT - (t - lastT), l)

        if maxT < l or r < minT or maxT < minT:
            out.append('NO')
            break
        lastT = t
    else:
        out.append('YES')
print '\n'.join(out)