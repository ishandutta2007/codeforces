import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    coupl = [[] for _ in range(n)]
    for _ in range(n - 1):
        u = inp[ii] - 1; ii += 1
        v = inp[ii] - 1; ii += 1
        coupl[u].append(v)
        coupl[v].append(u)

    bfs = [0]
    for node in bfs:
        bfs += coupl[node]
        for nei in coupl[node]:
            coupl[nei].remove(node)

    DP = [0] * n
    for node in reversed(bfs):
        DP[node] = 1 + sum(DP[child] for child in coupl[node])

    edges = []
    for i in bfs[1:]:
        edges.append(DP[i] * (n - DP[i]))
    edges.sort()
    
    m = inp[ii]; ii += 1
    P = inp[ii: ii + m]; ii += m

    P.sort()
    P.reverse()

    buckets = [1] * (n - 1)
    for i in range(max(0, n - 1 - m), n - 1):
        buckets[i] *= P.pop()

    while P:
        buckets[-1] = buckets[i] * P.pop() % MOD

    print sum(edges[i] * buckets[i] % MOD for i in range(n - 1)) % MOD