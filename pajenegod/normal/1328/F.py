import sys
range = xrange
input = raw_input


n, k = [int(x) for x in input().split()]
A = sorted(int(x) for x in input().split())

bigsum = sum(A)
bigcount = n

smallsum = 0
smallcount = 0

cur = 0
best = 10**18

i = 0
for a in set(A):    
    while i < n and A[i] == a:
        bigsum -= a
        bigcount -= 1
        cur += 1
        i += 1
    if cur >= k:
        best = 0
        break
    
    smallcost = (a - 1) * smallcount - smallsum
    bigcost = bigsum - (a + 1) * bigcount
    
    best = min(best, smallcost + bigcost + k - cur)

    if smallcount + cur >= k:
        best = min(best, smallcost + k - cur)

    if bigcount + cur >= k:
        best = min(best, bigcost + k - cur)

    smallsum += cur * a
    smallcount += cur
    cur = 0

print best