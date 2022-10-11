import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    C = inp[ii: ii + n]; ii += n
    A = inp[ii: ii + n]; ii += n
    B = inp[ii: ii + n]; ii += n

    C = [c - 1 for c in C]
    C.reverse()
    A.reverse()
    B.reverse()

    best = 0
    base = C[0]
    for i in range(n - 1):
        base += 2
        best = max(base + abs(A[i] - B[i]), best)
        
        if A[i] != B[i]:
            base = max(C[i + 1], base + C[i + 1] - abs(A[i] - B[i]))
        else:
            base = C[i + 1]
    print best