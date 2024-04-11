import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
B = inp[ii: ii + n]; ii += n

maxa = 0
A = []
for b in B:
    A.append(b + maxa)
    if b >= 0:
        maxa = A[-1]
print ' '.join(str(x) for x in A)