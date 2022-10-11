import sys
from collections import deque as dq
range = xrange
inp = [int(x)-1 for line in sys.stdin for x in line.split()]
ii = 0

n = inp[ii]+1
ii+=1

ind0 = ii+2*(n-1)
A = inp[ind0:ind0+n]

if A[0]!=0:
    print 'No'
    sys.exit()

mapp = [-1]*n
for i in range(n):
    mapp[A[i]]=i

coupl = [[] for _ in range(n)]
for _ in range(n-1):
    a,b = mapp[inp[ii]],mapp[inp[ii+1]]
    ii+=2
    coupl[a].append(b)
    coupl[b].append(a)

found = [False]*n
B = []

Q = dq()
Q.append(0)
found[0]=True
B.append(0)
while Q:
    node = Q.popleft()
    new = [nei for nei in coupl[node] if not found[nei]]
    new.sort()
    for nei in new:
        found[nei]=True
        B.append(nei)
        Q.append(nei)
if all(B[i]==i for i in range(n)):
    print 'Yes'
else:
    print 'No'