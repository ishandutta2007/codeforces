import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
P = [-1] + [p - 1 for p in inp[ii: ii + n - 1]]; ii += n - 1

children = [[] for _ in range(n)]
for node in range(1, n):
    children[P[node]].append(node)

DPdown = [-1]*n
for node in reversed(range(1, n)):
    val = 1
    for child in children[node]:
        val = val * DPdown[child] % MOD
    DPdown[node] = val + 1

# Set DPup[root] to default value
DPup = [1]*n
for node in range(n):
    prefix = [DPup[node]]
    suffix = [1]
    for child in children[node]:
        prefix.append(prefix[-1] * DPdown[child] % MOD)
    for child in reversed(children[node]):
        suffix.append(DPdown[child] * suffix[-1] % MOD)
    suffix.pop()
    prefix.pop()
    suffix.reverse()

    for i, child in enumerate(children[node]):
        DPup[child] = prefix[i] * suffix[i] % MOD + 1

out = [-1]*n
for node in range(n):
    prod = DPup[node]
    for child in children[node]:
        prod = prod * DPdown[child] % MOD
    out[node] = prod % MOD

print ' '.join(str(val) for val in out)