import sys
from collections import deque as dq
from collections import defaultdict as di
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

Q = dq()
inside = di(int)

for a in A:
    if inside[a]:
        continue
    
    if len(Q) == k:
        inside[Q.popleft()] -= 1

    Q.append(a)
    inside[a] += 1

print len(Q)
print ' '.join(str(x) for x in reversed(Q))