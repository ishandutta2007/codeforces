import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii:ii + n]; ii += n
    B = inp[ii:ii + n]; ii += n

    if not all(b == B[0] for b in B) or A == sorted(A):
        print 'Yes'
    else:
        print 'No'