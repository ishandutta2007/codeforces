import sys
range = xrange
input = raw_input
import heapq
 
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []
 
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    origx = x = inp[ii]; ii += 1
    y = inp[ii]; ii += 1
    B = inp[ii: ii + n]; ii += n
    
    unused = 1
    Bset = set(B)
    while unused in Bset:
        unused += 1
 
    buckets = [[] for _ in range(n + 2)]
    for i in range(n):
        buckets[B[i]].append(i)
    bucketslen = [len(b) for b in buckets]
    
    ans = [-1] * n
 
    heapq.cmp_lt = lambda i,j: bucketslen[i] > bucketslen[j]
    
    biggest_bucket = list(range(1, n + 2))
    heapq.heapify(biggest_bucket)
    while x:
        b = heapq.heappop(biggest_bucket)
        
        ans[buckets[b].pop()] = b
        bucketslen[b] -= 1
       
        heapq.heappush(biggest_bucket, b)
        x -= 1
        y -= 1
 
    order = sorted(range(1 , n + 2), key = lambda i: len(buckets[i]), reverse = True) 
    
    everything = list(buckets[order[0]])
    for i in reversed(order[1:]):
        everything += buckets[i]
    
    for i in order:
        for j in range(len(buckets[i])):
            ind = everything.pop()
            if y and B[ind] != i:
                ans[ind] = i
                y -= 1
            else:
                ans[ind] = unused
    
    X = sum(B[ind] == ans[ind] for ind in range(n))
    if X == origx and y == 0:
        out.append('YES')
        out.append(' '.join(str(x) for x in ans))
    else:
        out.append('NO')
print '\n'.join(out)