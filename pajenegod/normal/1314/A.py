import sys
import heapq
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
A = [x - 1 for x in inp[ii: ii + n]]; ii += n
T = [x for x in inp[ii: ii + n]]; ii += n

heapq.cmp_lt = lambda i,j: T[i] > T[j]

order = sorted(range(n), key = A.__getitem__)

vals = []
summa = 0

total = 0
i = 0
a = -1
while i < n or vals:
    if not vals:
        a = A[order[i]]
    while i < n and A[order[i]] == a:
        heapq.heappush(vals, order[i])
        summa += T[order[i]]
        i += 1
    
    j = heapq.heappop(vals)
    summa -= T[j]
    total += summa
    a += 1

print total