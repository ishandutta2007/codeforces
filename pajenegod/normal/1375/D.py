import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

def find_mex(A):
    n = len(A)
    count = [0] * (n + 2)
    for a in A:
        count[a] += 1
    return count.index(0)

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    
    X = []

    for i in range(n):
        while A[i] != i:
            mex = find_mex(A)
            if mex < n and A[mex] != mex:
                X.append(mex)
                A[mex] = mex
            else:
                j = A.index(i)
                X.append(j)
                A[j] = mex
    assert len(X) <= 2 * n
    print len(X)
    print ' '.join(str(x + 1) for x in X)