import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

val = [0]*n

for _ in range(m):
    u = inp[ii] - 1; ii += 1
    v = inp[ii] - 1; ii += 1
    d = inp[ii]; ii += 1
    val[u] -= d
    val[v] += d

#ans = sum(v for v in val if v > 0)

pairs = []
i = 0
j = 0
while i < n and j < n:
    while i < n and val[i] <= 0:
        i += 1
    while j < n and val[j] >= 0:
        j += 1
    if i == n or j == n:
        break
    x = min(val[i], -val[j])
    val[i] -= x
    val[j] += x
    pairs.append("%d %d %d" % (j+1, i+1, x))
    
print len(pairs)
print '\n'.join(pairs)