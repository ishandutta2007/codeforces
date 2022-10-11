from collections import deque as dq
import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

A.sort()

med = A[len(A)//2]
if sum(abs(a - med) for a in A) <= k:
    print 0
    sys.exit()

A = dq(A)

minval = A.popleft()
maxval = A.pop()
mincount = 1
maxcount = 1

while k>0 and minval != maxval:
    while A and A[0] == minval:
        A.popleft()
        mincount += 1

    while A and A[-1] == maxval:
        A.pop()
        maxcount += 1

    if mincount <= maxcount:
        if k < mincount:
            break

        use = k//mincount
        if A and minval + use > A[0]:
            use = A[0] - minval
        
        k -= use * mincount
        minval += use
    
    else:
        if k < maxcount:
            break

        use = k//maxcount
        if A and maxval - use < A[-1]:
            use = maxval - A[-1]
        
        k -= use * maxcount
        maxval -= use

print maxval - minval