import sys
from collections import defaultdict as di
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

t = int(inp[ii]); ii += 1
out = []
for _ in range(t):
    n = int(inp[ii]); ii += 1
    k = int(inp[ii]); ii += 1

    S = inp[ii]; ii += 1

    cost = 0
    found = [0]*n
    for i in range(n):
        if found[i]:
            continue
        
        counter = di(int)
        bfs = [i]
        for node in bfs:
            if node < 0 or node >= n or found[node]:
                continue
            found[node] = 1
            counter[S[node]] += 1
            bfs.append(n - node - 1)
            bfs.append(node + k)
            bfs.append(node - k)
        
        total = 0
        maxi = 0
        for char in counter:
            total += counter[char]
            maxi = max(maxi, counter[char])
        cost += total - maxi
    out.append(cost)
print '\n'.join(str(x) for x in out)