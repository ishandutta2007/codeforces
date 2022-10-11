import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    A = [abs(a) for a in A]
    A = [A[i] if i & 1 else -A[i] for i in range(n)]
    print ' '.join(str(x) for x in A)