import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []
 
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1
 
    coupl = [[] for _ in range(n)]
    for _ in range(n - 1):
        u = inp[ii] - 1; ii += 1
        v = inp[ii] - 1; ii += 1
        coupl[u].append(v)
        coupl[v].append(u)
    if k == 1:
        out.append(n - 1)
        continue
    leaves = [node for node in range(n) if len(coupl[node]) == 1]
    counter = [0]*n
 
    ans = 0
    for node in leaves:
        if counter[node] % k != 0:
            continue
        for nei in coupl[node]:
            counter[nei] += 1
            ans += counter[nei] % k == 0
            if counter[nei] + 1 == len(coupl[nei]):
                leaves.append(nei)
    out.append(ans)
print '\n'.join(str(x) for x in out)