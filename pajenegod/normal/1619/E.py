import sys
import bisect

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    
    cost = [0] * (n + 1)

    AA = A[:]
    A.sort(reverse = True)
    Astack = []
    for i in range(1, n + 1):
        while A and A[-1] < i:
            Astack.append(A.pop())

        if not Astack:
            for j in range(i, n + 1):
                cost[j] = -1
            break
        cost[i] += i - 1 - Astack.pop()
    
    for i in range(1, n + 1):
        if cost[i] >= 0:
            cost[i] += cost[i - 1]
    
    for a in AA:
        if cost[a] >= 0:
            cost[a] += 1
    
    print(' '.join(str(x) for x in cost))