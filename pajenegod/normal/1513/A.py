import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]

    A = list(range(1, n + 1))
    for i in range(2, n, 2):
        A[i], A[i - 1] = A[i - 1], A[i]
    
    for i in range(1, n - 1):
        k -= A[i - 1] <= A[i] >= A[i + 1]
        if k < 0:
            A[i:] = sorted(A[i:])
            break
    if k > 0:
        print -1
    else:
        print ' '.join(str(a) for a in A)