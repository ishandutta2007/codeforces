import sys

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1

    A = inp[ii: ii + n]; ii += n
    B = [A[i] - n + k + (i + 1) for i in range(n)]

    B.sort()

    s = 0
    for i in range(1, k + 1):
        s += i

    for i in range(n - k):
        s += B[i]

    for i in range(n):
        s += n - k - (i + 1)
    
    print(s)