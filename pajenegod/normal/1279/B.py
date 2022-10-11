import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    s = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    t = 0
    maxt = -1
    besta = 0
    skip = 0
    for i in range(n):
        t += A[i]
        if maxt == -1 or A[maxt] < A[i]:
            maxt = i
        if t <= s:
            if besta < i + 1:
                besta = i + 1
                skip = 0
        if t - A[maxt] <= s:
            if besta < i:
                besta = i
                skip = maxt + 1
    out.append(skip)
print '\n'.join(str(x) for x in out)