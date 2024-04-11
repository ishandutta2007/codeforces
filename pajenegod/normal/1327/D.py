import sys
from collections import defaultdict as di
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    P = [x - 1 for x in inp[ii: ii + n]]; ii += n
    C = [x - 1 for x in inp[ii: ii + n]]; ii += n
    
    best = n

    found = [0]*n
    for i in range(n):
        if found[i]:
            continue

        A = []
        B = []
        while not found[i]:
            A.append(C[i])
            B.append(i)
            found[i] = 1
            i = P[i]
        
        m = len(A)
        i = 1
        divs = []
        while i * i < m:
            if m % i == 0:
                divs.append(i)
                divs.append(m // i)
            
            i += 1
        if m % i == 0:
            divs.append(i)

        for d in divs:
            if d >= best:
                continue
            DP = [0]*m
            for j in reversed(range(m)):
                DP[j] = +(d + j >= m or (A[j] == A[j + d] and DP[j + d]))
            
            for j in range(d):
                if DP[j]:
                    best = d
    out.append(best)

print '\n'.join(str(x) for x in out)