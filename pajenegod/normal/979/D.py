import sys
range = xrange
input = raw_input

big = 10**5 + 1
M = 1
while M < big:
    M *= 2

mini = [0]
L = [0]
R = [0]

roots = [0]*big

def add(x, i):
    bits = []
    xx = x + M
    while xx != 1:
        bits.append(xx&1)
        xx >>= 1

    if not roots[i]:
        roots[i] = len(mini)
        mini.append(x)
        L.append(0)
        R.append(0)

    node = roots[i]
    mini[node] = min(mini[node], x)

    for b in reversed(bits):
        nesta = R if b else L
        if not nesta[node]:
            nesta[node] = len(mini)
            mini.append(x)
            L.append(0)
            R.append(0)
        node = nesta[node]
        mini[node] = min(mini[node], x)

found = [0]*big

divisors = [[] for _ in range(big)]
for i in range(1, big):
    ii = i
    while ii < big:
        divisors[ii].append(i)
        ii += i

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

q = inp[ii]; ii += 1
for _ in range(q):
    t = inp[ii]; ii += 1

    if t == 1:
        u = inp[ii]; ii += 1
        if not found[u]:
            found[u] = 1
            
            for d in divisors[u]:
                add(u, d)

    else:
        x = inp[ii]; ii += 1
        k = inp[ii]; ii += 1
        s = inp[ii]; ii += 1

        if x % k != 0:
            out.append(-1)
            continue
        s -= x

        node = roots[k]
        if not node or mini[node] > s:
            out.append(-1)
            continue
        
        xbits = []
        xx = x +  M
        while xx > 1:
            xbits.append(xx&1)
            xx >>= 1

        for bit in reversed(xbits):
            alt1,alt2 = (L[node],R[node]) if bit else (R[node],L[node])
            if alt1 and mini[alt1] <= s:
                node = alt1
            elif alt2 and mini[alt2] <= s:
                node = alt2
            else:
                break
        else:
            out.append(mini[node])
            continue
        out.append(-1)

print '\n'.join(str(x) for x in out)