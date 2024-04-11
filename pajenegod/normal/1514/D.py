import sys

sys.modules["hashlib"] = sys.sha512 = sys
import random

from bisect import bisect_left as lower_bound

range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
q = inp[ii]; ii += 1
A = inp[ii: ii + n]; ii += n

L = inp[ii + 0:ii + 2 * q:2]
R = inp[ii + 1:ii + 2 * q:2]
L = [l - 1 for l in L]

where = [[] for _ in range(n + 1)]
for i in range(n):
    where[A[i]].append(i)

rands = [random.randrange(10**9) for _ in range(30)]

def find_maj(l,r):
    maj = (r - l + 1) // 2
    for x in rands:
        a = A[l + x % (r - l)]
        B = where[a]

        ind = lower_bound(B, l) + maj - 1
        if ind < len(B) and B[ind] < r:
            return a
    return -1

out = []
for qind in range(q):
    l = L[qind]
    r = R[qind]
    m = r - l

    maj = find_maj(l,r)
    if maj == -1:
        out.append(1)
    else:
        B = where[maj]
        count = lower_bound(B,r) - lower_bound(B,l)

        count -= min(m - count, count)
        cost = max(count, 1)
        out.append(cost)

print '\n'.join(str(x) for x in out)