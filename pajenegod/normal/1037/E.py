
import sys
range = xrange

n,m,k = [int(x) for x in sys.stdin.readline().split()]

inp = [int(x)-1 for x in sys.stdin.read().split()]
ii = 0

coupl = [[] for _ in range(n)]
time = [[] for _ in range(n)]
nfr = [0]*n

for i in range(m):
    a,b = inp[ii],inp[ii+1]
    ii += 2
    coupl[a].append(b)
    coupl[b].append(a)
    time[a].append(i)
    time[b].append(i)
    nfr[a] += 1
    nfr[b] += 1

notf = 0

rem = [i for i in range(n) if nfr[i]<k]
while rem:
    node = rem.pop()
    notf += 1
    for nei in coupl[node]:
        if nfr[nei]==k:
            rem.append(nei)
        nfr[nei]-=1

out = []
for j in reversed(range(m)):
    out.append(n-notf)
    a,b = inp[j*2],inp[j*2+1]
    nfra = nfr[a]
    nfrb = nfr[b]

    if nfra>=k:
        if nfrb==k:
            rem.append(b)
        nfr[b]-=1
    if nfrb>=k:
        if nfra==k:
            rem.append(a)
        nfr[a]-=1
    
    while rem:
        node = rem.pop()
        notf += 1
        for i in range(len(coupl[node])):
            nei = coupl[node][i]
            t = time[node][i]
            if t<j:
                if nfr[nei]==k:
                    rem.append(nei)
                nfr[nei]-=1
print '\n'.join(str(x) for x in reversed(out))