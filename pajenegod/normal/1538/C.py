import sys
range = xrange
input = raw_input
import bisect


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    l = inp[ii]; ii += 1
    r = inp[ii]; ii += 1

    A = inp[ii: ii + n]; ii += n
    A.sort()
    
    count = 0
    for a in A:
        i = bisect.bisect_left(A, l - a)
        j = bisect.bisect_right(A, r - a)

        count += j - i - (l <= a + a <= r)

    print count // 2