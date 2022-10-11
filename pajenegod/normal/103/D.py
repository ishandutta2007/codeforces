import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

n = inp[ii]
ii += 1

A = [float(x) for x in inp[ii:ii + n]]
ii += n

queries = [[] for _ in range(n)]

q = inp[ii]
ii += 1

m = 500

ans = [0.0]*q
B = []
for _ in range(q):
    a = inp[ii] - 1
    ii += 1
    b = inp[ii]
    ii += 1
    B.append(b)
    
    if b >= m:
        i = a
        s = 0.0
        while i < n:
            s += A[i]
            i += b
        ans[_] = s
    else:
        queries[a].append(_)

buckets = [[0.0]*i for i in range(1, m)]
modvals = [n%b for b in range(1, m)]

for a in reversed(range(n)):
    val = A[a]


    for b in range(m - 1):
        if modvals[b] == 0:
            modvals[b] = b
        else:
            modvals[b] -= 1
        buckets[b][modvals[b]] += val 
    #for b,bucket in enumerate(buckets):
    #    bucket[a % (b + 1)] += val
    
    for qind in queries[a]:
        ans[qind] = buckets[B[qind] - 1][a % B[qind]] 

print '\n'.join(str(int(x)) for x in ans)