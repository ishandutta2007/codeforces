import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

def solve(n,A,B):
    if n & 1 and A[n >> 1] != B[n >> 1]:
        return False
    pairsA = []
    for i in range(n >> 1):
        a = A[i]
        b = A[~i]
        if a > b:
            a,b = b,a
        pairsA.append((a,b))
    pairsB = []
    for i in range(n >> 1):
        a = B[i]
        b = B[~i]
        if a > b:
            a,b = b,a
        pairsB.append((a,b))
    return sorted(pairsA) == sorted(pairsB)

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    B = inp[ii: ii + n]; ii += n

    print 'Yes' if solve(n,A,B) else 'No'