import sys
range = xrange
input = raw_input

def dister(root, coupl):
    dist = [-1]*len(coupl)
    dist[root] = 0
    bfs = [root]
    for node in bfs:
        for nei in coupl[node]:
            if dist[nei] == -1:
                dist[nei] = dist[node] + 1
                bfs.append(nei)
    return dist

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    a = inp[ii] - 1; ii += 1
    b = inp[ii] - 1; ii += 1
    c = inp[ii] - 1; ii += 1
    
    P = inp[ii: ii + m]; ii += m
    P.sort()
    Pcumsum = [0]
    for p in P:
        Pcumsum.append(Pcumsum[-1] + p)

    coupl = [[] for _ in range(n)]
    for _ in range(m):
        u = inp[ii] - 1; ii += 1
        v = inp[ii] - 1; ii += 1
        coupl[u].append(v)
        coupl[v].append(u)

    adist = dister(a, coupl)
    bdist = dister(b, coupl)
    cdist = dister(c, coupl)

    best = 4 * 10**18
    for node in range(n):
        da = adist[node]
        db = bdist[node]
        dc = cdist[node]
        if da + db + dc > m:
            continue
        
        val = 0
        count = 0
        
        val += 2 * (Pcumsum[count + db] - Pcumsum[count])
        count += db

        val += Pcumsum[count + da] - Pcumsum[count]
        count += da
    
        val += Pcumsum[count + dc] - Pcumsum[count]
        count += dc

        best = min(best, val)
    print best