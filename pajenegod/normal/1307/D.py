import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

out = []

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1
k = inp[ii]; ii += 1

A = [x - 1 for x in inp[ii: ii + k]]; ii += k

coupl = [[] for _ in range(n)]
for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    coupl[u].append(v)
    coupl[v].append(u)

d1 = [-1]*n
root = 0
bfs = [root]
d1[root] = 0
for node in bfs:
    for nei in coupl[node]:
        if d1[nei] == -1:
            d1[nei] = d1[node] + 1
            bfs.append(nei)

d2 = [-1]*n
root = n - 1
bfs = [root]
d2[root] = 0
for node in bfs:
    for nei in coupl[node]:
        if d2[nei] == -1:
            d2[nei] = d2[node] + 1
            bfs.append(nei)

shortest = d2[0]
order = sorted(A, key = lambda i: d1[i] - d2[i])
longest = 0
biggest_d1 = d1[order[0]]
for i in order[1:]:
    longest = max(longest, biggest_d1 + d2[i] + 1)
    biggest_d1 = max(biggest_d1, d1[i])
print min(shortest, longest)