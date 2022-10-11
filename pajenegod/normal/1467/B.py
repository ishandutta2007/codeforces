import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    def check(i):
        return +(0 < i < n - 1 and (A[i - 1] < A[i] > A[i + 1] or A[i - 1] > A[i] < A[i + 1]))
    
    B = [check(i) for i in range(n)]
    B.append(0)

    diff = 0
    for i in range(n):
        tmp = A[i]
        me = B[i]
        prev = B[i + 1] + B[i - 1] + me
        if i:
            A[i] = A[i - 1]
            diff = min(diff, check(i + 1) - prev)
        if i + 1 < n:
            A[i] = A[i + 1]
            diff = min(diff, check(i - 1) - prev)
        A[i] = tmp

    out.append(sum(B) + diff)

print '\n'.join(str(x) for x in out)