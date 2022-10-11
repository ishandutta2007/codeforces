import sys
range = xrange
input = raw_input

n,m,k = [int(x) for x in input().split()]

if n == k:
    print -1
    sys.exit()

A = [int(x) - 1 for x in input().split()]

marked = [0]*n
for a in A:
    marked[a] = 1

B = [i for i in range(n) if not marked[i]]

free = B.pop()

a = A.pop() if A else B.pop()
b = A.pop() if A else B.pop()

import itertools
out = []
for j in range(n):
    if j != free:
        out.append((free, j))

for i in range(n):
    if i == free:continue
    for j in range(i + 1, n):
        if len(out) >= m:
            break
        if j == free: 
            continue
        if (i == a and j == b) or (i == b and j == a):
            continue
        if (i == b and marked[j]) or (j == b and marked[i]):
            continue
        out.append((i,j))

if len(out) == m:
    print '\n'.join('%d %d' % (a + 1, b + 1) for a,b in out)
else:
    print -1