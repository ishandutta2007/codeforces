import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []
 
n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
k = inp[ii]; ii += 1
 
coupl = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)
 
depth = [-1]*n
root = 0
depth[root] = 0
bfs = [root]
P = [-1]*n
 
a = -1
b = -1
 
for node in bfs:
    for nei in coupl[node]:
        if depth[nei] != -1:
            if depth[nei] >= depth[node]:
                a = nei
                b = node
                break
        else:
            depth[nei] = depth[node] + 1
            P[nei] = node
            bfs.append(nei)
    else:
        continue
    break
 
odd = 0
for node in range(n):
    if depth[node] & 1:
        odd += 1

if a != -1:
    A = [a]
    B = [b]
    par = 1
    while a != b:
        if par:
            a = P[a]
            A.append(a)
        else:
            b = P[b]
            B.append(b)
        par ^= 1
    A.pop()
    A += reversed(B)

    if len(A) <= k:
        print 2
        print len(A)
        print ' '.join(str(x + 1) for x in A)
    else:
        print 1
        print ' '.join(str(x + 1) for x in A[::2][:k + 1 >> 1])
elif odd >= n - odd:
    print 1
    print ' '.join(str(x + 1) for x in [node for node in range(n) if depth[node] & 1][:k + 1 >> 1])
else:
    print 1
    print ' '.join(str(x + 1) for x in [node for node in range(n) if depth[node] & 1 == 0][:k + 1 >> 1])