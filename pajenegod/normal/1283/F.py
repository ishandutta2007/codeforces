import sys
import heapq
range = xrange
input = raw_input
 
n = int(input())
A = [int(x) - 1 for x in input().split()]
root = A[0]
 
counter = [0]*n
for a in A:
    counter[a] += 1
 
heap = [i for i in range(n) if counter[i] == 0]
heapq.heapify(heap)
 
pairs = []
 
for a in reversed(A):
    if heap:
        val = heapq.heappop(heap)
        pairs.append((val, a))
        counter[a] -= 1
        if counter[a] == 0:
            heapq.heappush(heap, a)
    else:
        print -1
        sys.exit()
pairs.reverse()
 
print root + 1
print '\n'.join('%d %d' % (u + 1, v + 1) for u,v in pairs)