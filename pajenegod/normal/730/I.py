import heapq
import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
p = inp[ii]; ii += 1
s = inp[ii]; ii += 1

A = inp[ii:]

heapq.cmp_lt = lambda i,j: A[i] < A[j]

order = sorted(range(n), key = lambda i: A[i + n] - A[i])

inf = 10**9

bestAsum = [-inf]*n
bestA = []

Asum = 0
for ind,i in enumerate(order):
    if len(bestA) < p or A[bestA[0]] < A[i]:
        heapq.heappush(bestA, i)
        Asum += A[i]
    if len(bestA) > p:
        Asum -= A[heapq.heappop(bestA)]
    
    if len(bestA) == p:
        bestAsum[ind] = Asum

bestBsum = [-inf]*n
bestB = []

Bsum = 0
for ind,i in reversed(list(enumerate(order))):
    if len(bestB) < s or A[bestB[0]] < A[i + n]:
        heapq.heappush(bestB, i + n)
        Bsum += A[i + n]
    if len(bestB) > s:
        Bsum -= A[heapq.heappop(bestB)]
    
    if len(bestB) == s:
        bestBsum[ind] = Bsum


split = max(range(n - 1), key = lambda ind: bestAsum[ind] + bestBsum[ind + 1])
score = bestAsum[split] + bestBsum[split + 1]

bestA = []
for ind in range(split + 1):
    i = order[ind]
    if len(bestA) < p or A[bestA[0]] < A[i]:
        heapq.heappush(bestA, i)
    if len(bestA) > p:
        A[heapq.heappop(bestA)]

bestB = []
for ind in range(split + 1, n):
    i = order[ind]
    if len(bestB) < s or A[bestB[0]] < A[i + n]:
        heapq.heappush(bestB, i + n)
    if len(bestB) > s:
        A[heapq.heappop(bestB)]

print score
print ' '.join(str(x + 1) for x in bestA)
print ' '.join(str(x + 1 - n) for x in bestB)