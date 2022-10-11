import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

n = inp[ii]; ii += 1
A = inp[ii: ii + n]; ii += n


B = list(A)

def swap(i, j):
    B[i],B[j] = B[j],B[i]
    out.append(j)
    out.append(i)
    

for i in reversed(range(n)):
    inv = [j for j in range(i) if A[j] > A[i]]
    inv = sorted(inv, key = A.__getitem__)

    for j in inv:
        swap(i,j)
print len(out) // 2
print ' '.join(str(x + 1) for x in out)