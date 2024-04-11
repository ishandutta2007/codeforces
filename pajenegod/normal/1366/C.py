import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    A = inp[ii: ii + n * m]; ii += n * m

    k = n + m - 1
    count0 = [0] * k
    count1 = [0] * k
    for y in range(n):
        for x in range(m):
            ind = y * m + x
            diff = x + y
            d0 = diff
            d1 = k - 1 - diff
            if d0 == d1:
                continue
            diff = min(d0, d1)
            if A[ind]:
                count1[diff] += 1
            else:
                count0[diff] += 1
    cost = 0
    for i in range(k):
        c0 = count0[i]
        c1 = count1[i]
        cost += min(c0, c1)
    print cost