import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    B = []
    for i in range(n):
        if A[i] == -1:
            if i + 1 < n and A[i + 1] != -1:
                B.append(A[i + 1])
            if i and A[i - 1] != -1:
                B.append(A[i - 1])
    
    C = [abs(A[i] - A[i + 1]) for i in range(n - 1) if A[i]>= 0 and A[i + 1]>=0]
    if not C:
        maxdiff = 0
    else:
        maxdiff = max(C)
    
    if B:
        minb = min(B)
        maxb = max(B)
        out.append('%d %d' % (max(maxdiff, maxb - minb + 1 >> 1), minb + maxb >> 1))
    else:
        out.append('%d 0' % maxdiff)
print '\n'.join(out)