import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    A = [A[i] for i in range(n) if i == 0 or i == n - 1 or A[i - 1] > A[i] < A[i + 1] or A[i - 1] < A[i] > A[i + 1]]

    out.append(len(A))
    out += A
    
print ' '.join(str(x) for x in out)