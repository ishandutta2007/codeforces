import sys
from collections import defaultdict
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    
    buckets = defaultdict(lambda:[-1])
    for i in range(n):
        buckets[A[i]].append(i)

    besta = -1
    for b in buckets:
        bucket = buckets[b]
        bucket.append(n)

        m = len(bucket)
        cand = 0
        for j in range(m - 1):
            cand += bucket[j] + 1 != bucket[j + 1]
        if besta == -1 or cand < besta:
            besta = cand
    print besta