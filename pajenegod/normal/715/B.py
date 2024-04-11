import sys
import heapq
range = xrange
input = raw_input

inf = 1e9+10

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
L = inp[ii]; ii += 1
s = inp[ii]; ii += 1
t = inp[ii]; ii += 1

U = inp[ii::3]
V = inp[ii+1::3]
W = [float(x) for x in inp[ii+2::3]]

coupl = [[] for _ in range(n)]
for i in range(m):
    coupl[U[i]].append(i)
    coupl[V[i]].append(~i)

class segtree:
    def __init__(s,n):
        s.m = 1
        while s.m < n: s.m *= 2
        s.data = [inf]*(s.m + s.m)
    def popmin(s):
        ind = 1
        v = s.data[ind]
        while ind < s.m:
            ind *= 2
            if s.data[ind] != v:
                ind += 1
            assert(s.data[ind] == v)

        indcopy = ind
        v = inf
        while ind:
            s.data[ind] = v
            v = min(v, s.data[ind ^ 1])
            ind >>= 1
        return indcopy - s.m
    def set(s, ind, val):
        ind += s.m
        while ind:
            s.data[ind] = val
            val = min(val, s.data[ind ^ 1])
            ind >>= 1

def dijk():
    seg = segtree(n)
    seg.set(s, 0)
    dist = [inf]*n
    dist[s] = 0

    while seg.data[1] < inf:
        node = seg.popmin()
        d = dist[node]
        for edge in coupl[node]:
            if edge < 0:
                nei = U[~edge]
                wei = W[~edge]
            else:
                nei = V[edge]
                wei = W[edge]
            if d + wei < dist[nei]:
                dist[nei] = d + wei
                seg.set(nei, d + wei)
    
    return dist[t]

picks = [i for i in range(m) if W[i] == 0.0]
for i in picks:
    W[i] = 1.0

def printer(f):
    if f:
        out = ['YES']
        for i in range(m):
            out.append('%d %d %d' % (U[i],V[i],int(W[i])))
        print '\n'.join(out)
    else:
        print 'NO'
    sys.exit()

d = dijk()
if d == L:
    printer(1)

if d > L or not picks:
    printer(0)

cur = list(picks)
while len(cur)>1:
    top = cur[len(cur)//2:]
    for i in top:
        W[i] = inf
    if dijk() > L:
        cur = top
        for i in top:
            W[i] = 1.0
    else:
        cur = cur[:len(cur)//2]

final = cur[0]
a = 1
b = L
while a<b:
    c = a + b + 1 >> 1
    W[final] = 1.0*c
    if dijk() <= L:
        a = c
    else:
        b = c - 1

W[final] = 1.0*a
printer(dijk() == L)