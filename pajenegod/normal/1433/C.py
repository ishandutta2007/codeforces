import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    Amax = max(A)
    if all(a == Amax for a in A):
        print -1
    else:
        i = 0
        while A[i] != Amax or not ((i and A[i - 1] != Amax) or (i + 1 < n and A[i + 1] != Amax)):
            i += 1
        print i + 1