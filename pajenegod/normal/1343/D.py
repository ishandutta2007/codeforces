import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    for i in range(n//2):
        A[i], A[~i] = min(A[i],A[~i]), max(A[i], A[~i])

    too_small = [0]*(2*k + 2)
    too_large = [0]*(2*k + 2)
    equal = [0]*(2*k + 1)
    for i in range(n//2):
        a = A[i]
        b = A[~i]
        equal[a + b] += 1
        too_small[a] += 1
        too_large[b + k + 1] += 1

    x = 0
    for j in range(len(too_large)):
        x += too_large[j]
        too_large[j] = x

    x = 0
    for j in reversed(range(len(too_small))):
        x += too_small[j]
        too_small[j] = x

    best = 2 * n
    for x in range(2, 2 * k + 1):
        # 0: equal
        # 1: n//2 - too_large - too_small - equal
        # 2: too_large + too_small
        best = min(best, n//2 + too_large[x] + too_small[x] - equal[x])
    print best