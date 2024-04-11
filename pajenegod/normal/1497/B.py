import sys
range = xrange
input = raw_input
from collections import defaultdict as di

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n,m = inp[ii: ii + 2]; ii += 2
    A =   inp[ii: ii + n]; ii += n
    
    marker = di(int)

    for a in A:
        marker[a % m] += 1
        marker[(m - a) % m] += 0

    ans = 0
    for a in list(marker):
        A1 = marker[a]
        A2 = marker[(m - a) % m]
        if A1 > A2:
            A1,A2 = A2,A1

        if (a+a) % m == 0:
            #x = marker[a]
            #left = 0
            ans += 2
        else:
            x = A1 + min(A2, A1 + 1)
            left = A1 + A2 - x
            ans += left + 1
    print ans//2