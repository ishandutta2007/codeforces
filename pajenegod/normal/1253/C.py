import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
A.sort()

Aextra = [0]*m

out = []
used = 0
pen = 0
for i in range(n):
    a = A[i]
    Aextra[used] += a
    pen += Aextra[used]
    used += 1
    if used == m:
        used = 0
    out.append(pen)
print ' '.join(str(x) for x in out)