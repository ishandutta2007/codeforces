import sys
import heapq
range = xrange
input = raw_input

n,m,r,k = [int(x) for x in input().split()]

A = [0]*n
for i in range(n):
    x1 = max(0, i - r + 1)
    x2 = min(i, n - r)
    A[i] = x2 - x1 + 1

norm = 1.0/(n - r + 1)
Af = [a*norm for a in A]

B = [0]*m
for i in range(m):
    x1 = max(0, i - r + 1)
    x2 = min(i, m - r)
    B[i] = x2 - x1 + 1

norm = 1.0/(m - r + 1)
Bf = [b*norm for b in B]

Af.sort(reverse=True)
Bf.sort(reverse=True)

heapq.cmp_lt = lambda (i,j),(k,l): Af[i]*Bf[j] > Af[k]*Bf[l] 

count = 0
ans = 0
A = [(0,0)]
used = set([(0,0)])

while count < k:
    i,j = heapq.heappop(A)
    count += 1
    ans += Af[i]*Bf[j]
    if i + 1 < n and (i+1,j) not in used:
        used.add((i+1,j))
        heapq.heappush(A, (i + 1,j))
    
    if j + 1 < m and (i,j+1) not in used:
        used.add((i,j+1))
        heapq.heappush(A, (i,j + 1))
        
print ans