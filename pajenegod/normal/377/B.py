import sys
import heapq
range = xrange
input = raw_input

n,m,s = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

Bind = sorted(range(n),key=lambda i:B[i])
Aind = sorted(range(m),key=lambda i:A[i])


big = 10**9+10

def solve(days):
    cheapest = []
    used = [0]*n
    fixes = [-1]*m
    cost = 0

    Ccopy = C[:]
    heapq.cmp_lt = lambda i,j: Ccopy[i]<Ccopy[j]

    j = len(Bind)-1
    for i in reversed(Aind):
        while j>=0 and B[Bind[j]]>=A[i]:
            heapq.heappush(cheapest, Bind[j])
            j -= 1
        
        if not cheapest: return big,None
        stud = heapq.heappop(cheapest)
        
        cost += Ccopy[stud]
        if cost >= big: return big,None
        Ccopy[stud] = 0
        

        used[stud] += 1
        fixes[i] = stud

        if used[stud]<days:
            heapq.heappush(cheapest, stud)

    return cost,fixes


l = 1
r = 10**5+1
while l<r:
    mid = (l+r)//2
    cost, fixes = solve(mid)

    if cost<=s:
        r = mid
    else:
        l = mid+1

if r == 10**5+1:
    print 'NO'
else:
    print 'YES'
    _, fixes = solve(l)
    print ' '.join(str(x+1) for x in fixes)