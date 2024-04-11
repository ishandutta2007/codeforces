import sys
from collections import deque
range = xrange
input = raw_input

m,k,n,s = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

big = 5*10**5+10
Bcount = [0]*big
for b in B:
    Bcount[b] += 1
counter = [b for b in Bcount]

besta = big
besta_int = None

Q = deque()
found = 0
for i in range(m):
    a = A[i]
    if Bcount[a]>0:
        Q.append((a,i))
        counter[a]-=1
        if counter[a]>=0:
            found += 1

    while Q and counter[Q[0][0]]<0:
        counter[Q[0][0]] += 1
        Q.popleft()

    if found==s:
        l = Q[0][1]
        l = k*(l//k)
        r = i+1
        
        score = max(0,r-(l+k))
        if score<besta:
            besta = score
            besta_int = r


if besta==big or m-besta<n*k:
    print -1
    sys.exit()

rem = []
i = besta_int - 1
while besta>0:
    if Bcount[A[i]]>0:
        Bcount[A[i]]-=1
    else:
        rem.append(i)
        besta-=1
    i-=1

print len(rem)
print ' '.join(str(x+1) for x in rem)