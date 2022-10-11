from __future__ import division
import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
 
coupl = [[] for _ in range(n)]
V = []
C = []
for _ in range(m):
    a = inp[ii] - 1; ii += 1
    b = inp[ii] - 1; ii += 1
    c = inp[ii]; ii += 1
    
    eind = len(V)
    C.append(c)
    V.append(b)
    V.append(a)
    coupl[a].append(eind)
    coupl[b].append(eind ^ 1)
 
found = [0]*n
ans = [0] * n
 
val0 = [0] * n
val1 = [1] * n
for root in range(n):
    if found[root]:
        continue
    bfs = [root]
    found[root] = 1
    for node in bfs:
        for eind in coupl[node]:
            nei = V[eind]
            if not found[nei]:
                found[nei] = 1
                bfs.append(nei)
 
                c = C[eind >> 1]
                val0[nei] = c - val0[node]
                val1[nei] = -val1[node]
 
    for node in bfs:
        for eind in coupl[node]:
            nei = V[eind]
            c = C[eind >> 1]
            if val0[node] + val0[nei] != c or val1[node] + val1[nei]:
                if val1[node] + val1[nei] == 0:
                    print 'NO'
                    sys.exit()
                x = (c - (val0[node] + val0[nei])) / (val1[node] + val1[nei])
                break
        else:
            continue
        break
    else:
        vals = []
        for node in bfs:
            #val0[node] + x*val1[node] = 0
            vals.append(-val0[node] // val1[node])
        vals.sort()
        x = vals[len(vals)//2]
 
    for node in bfs:
        ans[node] = val0[node] + x * val1[node]
 
for node in range(n):
    for eind in coupl[node]:
        nei = V[eind]
        c = C[eind >> 1]
        if ans[node] + ans[nei] != c:
            print 'NO'
            sys.exit()
 
print 'YES'
print ' '.join(str(x) for x in ans)