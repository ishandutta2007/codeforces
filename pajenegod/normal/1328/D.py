import sys
range = xrange
input = raw_input

q = int(input())
for _ in range(q):
    n = int(input())
    T = [int(x) for x in input().split()]

    if all(t == T[0] for t in T):
        print 1
        print '1 '*n
        continue

    if n&1==0:
        print 2
        print ' '.join(str(1 + (x & 1)) for x in range(n))
        continue

    i = 0
    while i < n and T[i - 1] != T[i]:
        i += 1

    if i < n:
        A = [c&1 for c in range(i)]
        A += [(c + 1) & 1 for c in range(i, n)]
        print 2
        print ' '.join(str(x + 1) for x in A)
        continue

    A = [c % 3 for c in range(n)]
    if A[-2] != A[0]:
        A[-1] = A[-2] ^ A[0] ^ 0 ^ 1 ^ 2
    print 3
    print ' '.join(str(x + 1) for x in A)
    continue