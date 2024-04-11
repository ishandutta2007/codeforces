import sys, collections
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    if all(A[0] == a for a in A):
        print 'NO'
        continue

    edges = []
    for i in range(1, n):
        if A[0] != A[i]:
            j = i
            edges.append((0,i))
    for i in range(1, n):
        if A[i] == A[0]:
            edges.append((j, i))
    print 'YES'
    print '\n'.join('%d %d'%(a + 1, b + 1) for a,b in edges)