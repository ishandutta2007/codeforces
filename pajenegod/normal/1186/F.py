import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

U = []
coupl = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    U.append(u)
    U.append(v)
    coupl[u].append(2*_)
    coupl[v].append(2*_ + 1)

rem = [0]*m
counter = [len(c) - 1 for c in coupl]
remcounter = [0]*n

keep = []

for node in range(n):
    par = 0
    if (len(coupl[node]) - remcounter[node]) & 1:
        while (len(coupl[node]) - remcounter[node]) & 1:
            while rem[coupl[node][counter[node]] >> 1]: counter[node] -= 1
            eind = coupl[node][counter[node]]
            
            par ^= 1
            if par:
                keep.append(eind)
            
            rem[eind >> 1] = 1
            remcounter[node] += 1
            node = U[eind ^ 1]
            remcounter[node] += 1
        if not par:
            keep.append(eind)

for root in range(n):
    node = root
    par = 0
    while len(coupl[root]) != remcounter[root]:
        while rem[coupl[node][counter[node]] >> 1]: counter[node] -= 1
        eind = coupl[node][counter[node]]
        
        par ^= 1
        if par:
            keep.append(eind)
        
        rem[eind >> 1] = 1
        remcounter[node] += 1
        node = U[eind ^ 1]
        remcounter[node] += 1

print len(keep)
print '\n'.join('%d %d' % (U[eind] + 1, U[eind ^ 1] + 1) for eind in keep)