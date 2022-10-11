import sys
from collections import defaultdict
range = xrange
input = raw_input

inf = 10**18

def solve(A,B,X,Y):
    na = len(A)
    nb = len(B)
    m = len(X)

    order = sorted([i for i in range(na) if A[i] >= 0], key = A.__getitem__)
    non_valid = defaultdict(set)
    
    for ind in range(m):
        i = X[ind]
        j = Y[ind]
        non_valid[j].add(i)

    DP = [-1] * nb
    for j in range(nb):
        avoid = non_valid[j]

        for i in order:
            if i not in avoid:
                DP[j] = B[j] + A[i]
                break
    return DP

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

n1,n2,n3,n4 = inp[ii:ii + 4]; ii += 4

A = inp[ii: ii + n1]; ii += n1
B = inp[ii: ii + n2]; ii += n2
C = inp[ii: ii + n3]; ii += n3
D = inp[ii: ii + n4]; ii += n4

m1 = inp[ii]; ii += 1
X1 = inp[ii + 0: ii + 2 * m1: 2]
Y1 = inp[ii + 1: ii + 2 * m1: 2]
ii += 2 * m1

m2 = inp[ii]; ii += 1
X2 = inp[ii + 0: ii + 2 * m2: 2]
Y2 = inp[ii + 1: ii + 2 * m2: 2]
ii += 2 * m2

m3 = inp[ii]; ii += 1
X3 = inp[ii + 0: ii + 2 * m3: 2]
Y3 = inp[ii + 1: ii + 2 * m3: 2]
ii += 2 * m3

X1 = [x - 1 for x in X1]
X2 = [x - 1 for x in X2]
X3 = [x - 1 for x in X3]

Y1 = [x - 1 for x in Y1]
Y2 = [x - 1 for x in Y2]
Y3 = [x - 1 for x in Y3]

E = A
E = solve(E,B,X1,Y1)
E = solve(E,C,X2,Y2)
E = solve(E,D,X3,Y3)

E = [e for e in E if e >= 0]
print min(E) if E else -1