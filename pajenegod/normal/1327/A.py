import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

precalc = [0]
while precalc[-1] <= 10**8:
    precalc.append(precalc[-1] + 2 * len(precalc) - 1)

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1

    if (n - k) & 1 or k >= len(precalc) or precalc[k] > n:
        out.append('NO')
    else:
        out.append('YES')

print '\n'.join(out)