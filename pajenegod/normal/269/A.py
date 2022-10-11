import sys
from collections import defaultdict
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

K = inp[ii + 0: ii + 2 * n: 2]
A = inp[ii + 1: ii + 2 * n: 2]

counter = defaultdict(int)

for i in range(n):
    k = K[i]
    counter[k] += A[i]

maxval = 0
for k in counter:
    a = counter[k]
    i = k
    while a > 1:
        a = (a + 3) // 4
        i += 1
    maxval = max(maxval, i, k + 1)
print maxval