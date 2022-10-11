import sys
from collections import defaultdict
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0
out = []

alpha = [chr(c) for c in range(ord('a'), ord('z') + 1)]

t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    k = int(inp[ii]); ii += 1

    A = inp[ii]; ii += 1
    B = inp[ii]; ii += 1

    Abuckets = defaultdict(int)
    Bbuckets = defaultdict(int)

    for a in A:
        Abuckets[a] += 1
    for b in B:
        Bbuckets[b] += 1

    for c in alpha:
        while Abuckets[c] > Bbuckets[c]:
            Abuckets[c] -= k
            Abuckets[chr(ord(c) + 1)] += k

    for c in list(Abuckets) + list(Bbuckets):
        if Abuckets[c] != Bbuckets[c]:
            out.append('NO')
            break
    else:
        out.append('YES')

print '\n'.join(out)