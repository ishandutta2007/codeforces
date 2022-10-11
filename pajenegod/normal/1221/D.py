import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

out = []

q = inp[ii]
ii += 1
for _ in range(q):
    n = inp[ii]
    ii += 1
    A = inp[ii:ii + 2*n: 2]
    B = inp[ii+1: ii + 2*n: 2]
    ii += 2*n

    besta = [0,B[0],B[0] * 2]
    prev = A[0]
    for i in range(1, n):
        b = B[i]
        cur = A[i]
        besta = [min(besta[j] + i*b for j in range(3) if cur + i != prev + j) for i in range(3)]
        prev = cur
    out.append(min(besta))
print '\n'.join(str(x) for x in out)