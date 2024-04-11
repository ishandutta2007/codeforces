from __future__ import print_function,division
import os,sys,atexit

if sys.version_info[0] < 3:
    range = xrange
    from cStringIO import StringIO as BytesIO
    sys.stdout = BytesIO()
else:
    from io import BytesIO
    sys.stdout = BytesIO()
    _write = sys.stdout.write
    sys.stdout.write = lambda s: _write(s.encode())
atexit.register(lambda: os.write(1, sys.stdout.getvalue()))

input = BytesIO(os.read(0, os.fstat(0).st_size)).readline


from collections import defaultdict as dd, deque
n = int(input())
A = [int(x) for x in input().split()]
cA = [0]
for a in A:
    cA.append(cA[-1] + a)

B = dd(list)

for r in range(1,n+1):
    for l in range(r):
        s = cA[r] - cA[l]
        B[s].append((l,r))

best = 0
bestA = None
for A in B.values():
    res = 0
    lr = -1
    for l,r in A:
        if lr <= l:
            lr = r
            res += 1

    if res > best:
        best = res
        bestA = A

print(best)
res = 0
lr = -1
for l,r in bestA:
    if lr <= l:
        lr = r
        res += 1
        print(l+1,r)