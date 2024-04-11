import sys
range = xrange
input = raw_input


def eulerian_cycle(coupl, V):
    for c in coupl:
        if len(c) & 1:
            return None
    m = len(V) >> 1
    found = [0]*m
    cycle = []
    
    stack = [0]
    while stack:
        eind = stack.pop()
        if eind < 0:
            eind = ~eind
            cycle.append(eind)
            node = V[eind ^ 1]
        else:
            node = V[eind]
        while coupl[node]:
            eind = coupl[node].pop()
            if not found[eind >> 1]:
                found[eind >> 1] = 1
                stack.append(~eind)
                stack.append(eind)
                break
    if len(cycle) == m:
        return cycle
    else:
        return None


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
 
m = 20
mshift = 1 << m
bitreverse = [0] * mshift
for i in range(1, mshift):
    x = i.bit_length() - 1
    bitreverse[i] = (mshift >> x + 1) + bitreverse[i - (1 << x)]
 
n = inp[ii]; ii += 1
A = [bitreverse[a] for a in inp[ii:]]
 
B = [[] for _ in range(mshift)]
for i in range(2 * n):
    B[A[i]].append(i)
 
while len(B) > 1:
    found = [0] * len(B)
    bfs = [A[0]]
    found[A[0]] = 1
    count = 0
    odd = 0
    for val in bfs:
        t = len(B[val])
        count += t
        odd += t & 1
        for i in B[val]:
            x = A[i ^ 1]
            if not found[x]:
                found[x] = 1
                bfs.append(x)
    
    if not odd and count == 2 * n:
        break
 
    B2 = B[::2]
    for i in range(1,len(B),2):
        B2[i >> 1] += B[i]
    B = B2
    for i in range(2 * n):
        A[i] >>= 1
 
ans = len(B).bit_length() - 1

for i in range(0, 2 * n, 2):
    A[i], A[i + 1] = A[i + 1], A[i]

cycle = eulerian_cycle(B, A)
out = []
for i in cycle:
    out.append(i ^ 1)
    out.append(i)

print ans
print ' '.join(str(x + 1) for x in out)