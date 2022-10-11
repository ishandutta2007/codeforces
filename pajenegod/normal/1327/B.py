import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    picked1 = [0]*n
    picked2 = [0]*n
    for _ in range(n):
        k = inp[ii]; ii += 1
        G = [g - 1 for g in inp[ii:ii + k]]; ii += k

        for g in G:
            if not picked2[g]:
                picked2[g] = 1
                picked1[_] = 1
                break
    if not all(picked1) and not all(picked2):
        i = 0
        while picked1[i]: i += 1
        j = 0
        while picked2[j]: j += 1
        out.append('IMPROVE')
        out.append('%d %d' % (i + 1, j + 1))
    else:
        out.append('OPTIMAL')
print '\n'.join(out)