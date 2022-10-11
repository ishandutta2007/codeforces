import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

q = inp[ii]; ii += 1

out = []
for _ in range(q):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    out.append((sum(A) + n - 1) // n)
print '\n'.join(str(x) for x in out)