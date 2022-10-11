import sys
range = xrange
input = raw_input

MOD = 998244353

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
coupl = [[] for _ in range(n)]
for _ in range(n - 1):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

leaf = 0
while len(coupl[leaf]) > 1:
    leaf += 1

root = leaf
bfs = [root]
for node in bfs:
    for nei in coupl[node]:
        del coupl[nei][coupl[nei].index(node)]
    bfs += coupl[node]

DP0 = [0]*n
DP2 = [0]*n
DP4 = [0]*n
DP6 = [0]*n

for node in reversed(bfs):
    a = 1
    for child in coupl[node]:
        fac = (DP2[child] + DP4[child] + DP6[child]) % MOD
        a = a * fac % MOD 
    DP0[node] = int(a)

    c = 1
    for child in coupl[node]:
        fac = (DP4[child] + DP6[child]) % MOD
        c = c * fac % MOD
    DP4[node] = int((a - c) % MOD)

    e = 1
    for child in coupl[node]:
        fac = (DP0[child] + DP2[child] + DP4[child] + DP6[child]) % MOD
        e = e * fac % MOD

    DP6[node] = DP2[node] = int(e)

print (DP4[root] + DP6[root] - 1) % MOD