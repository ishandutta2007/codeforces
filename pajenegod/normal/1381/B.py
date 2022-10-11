import sys
range = xrange
input = raw_input

from collections import Counter
def subsetssum(A, n):
    bitset = 1 << n
    for i, c in Counter(A).items():
        c = min(c, n // i)
        while c > 2:
            rem = c + 1 >> 1
            bitset |= bitset >> i * rem
            c -= rem
        if c:
            bitset |= bitset >> i
            if c > 1:
                bitset |= bitset >> i
    return bitset & 1


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []
 
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + 2 * n]; ii += 2 * n
    A = [a - 1 for a in A]
 
    bits = []
    while A:
        b = max(A)
        i = A.index(b)
        bits.append(len(A) - i)
        del A[i:]
 
    out.append('YES' if subsetssum(bits, n) else 'NO')
print '\n'.join(out)