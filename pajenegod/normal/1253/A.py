import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1

out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii:ii + n]; ii += n
    B = inp[ii:ii + n]; ii += n

    C = [B[i] - A[i] for i in range(n)]

    i = 0
    while i < n and C[i] == 0:
        i += 1

    j = n - 1
    while j >= 0 and C[j] == 0:
        j -= 1

    if i == n or (C[i] > 0 and all(c == C[i] for c in C[i:j + 1])):
        out.append('YES')
    else:
        out.append('NO')

print '\n'.join(out)