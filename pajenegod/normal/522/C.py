import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []

for _ in range(t):
    m = inp[ii] - 1; ii += 1
    k = inp[ii]; ii += 1

    A = inp[ii:ii + k]; ii += k

    T = inp[ii + 0:ii + 2 * m: 2]
    R = inp[ii + 1:ii + 2 * m: 2]

    ii += 2 * m

    first_empty = m
    last_seen = [-1]*k

    for i in range(m):
        if R[i]:
            first_empty = i
            break

    for i in range(m):
        if T[i]:
            last_seen[T[i] - 1] = i
            A[T[i] - 1] -= 1

    empty = []
    if first_empty != m:
        s = 0
        for i in range(first_empty):
            if not T[i]:
                s += 1

        for j in range(k):
            if A[j] <= s and last_seen[j] < first_empty:
                empty.append(j)

        Aj = min(A[j] for j in empty)
    else:
        Aj = 0

    s = 0
    for i in range(m):
        if not T[i]:
            s += 1

    for j in range(k):
        if A[j] <= s - Aj:
            empty.append(j)

    empty = set(empty)
    out.append(''.join('Y' if j in empty else 'N' for j in range(k)))

print '\n'.join(out)