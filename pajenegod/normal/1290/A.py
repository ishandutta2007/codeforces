import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii] - 1; ii += 1
    k = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    maxA = max(A)
    best = 0
    x = max(0, m - k)
    y = max(0, m - x)
    for left in range(0, y + 1):
        right = y - left
        
        val = maxA
        ind1 = left
        ind2 = n - 1 - right - x
        while ind1 <= left + x:
            val = min(val, max(A[ind1], A[ind2]))
            ind1 += 1
            ind2 += 1
        if val > best:
            best = val
    out.append(best)
print '\n'.join(str(x) for x in out)