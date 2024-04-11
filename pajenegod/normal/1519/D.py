import _numpypy

import sys
range = xrange
input = raw_input

zero = _numpypy.multiarray.dtype('int64').type()

inp = [int(x) for x in sys.stdin.read().split()]
n = inp[0]
A = inp[1:n + 1]
B = inp[n + 1:]

AA = _numpypy.multiarray.zeros(n, dtype = 'int64')
BB = _numpypy.multiarray.zeros(n, dtype = 'int64')
for i in range(n):
    AA[i] = A[i]
    BB[i] = B[i]

best = base = zero
for i in range(n):
    base += AA[i] * BB[i]

for r in range(2, n + 1):
    l = 0

    i = l + (r - l - 1) // 2
    j = l + (r - l) // 2

    s = zero
    while j < r:
        s += (AA[i] - AA[j]) * (BB[j] - BB[i])
        if s > best:
            best = s
        j += 1
        i -= 1

for l in range(n):
    r = n

    i = l + (r - l - 1) // 2
    j = l + (r - l) // 2

    s = zero
    while j < r:
        s += (AA[i] - AA[j]) * (BB[j] - BB[i])
        if s > best:
            best = s
        j += 1
        i -= 1

print int(base + best)