import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

P0 = [x - 1 for x in inp[ii: ii + n]]; ii += n
V = [x - 1 for x in inp[ii: ii + m]]; ii += m
B = inp[ii: ii + m]; ii += m

P = [P0]
for _ in range(19):
    Pprev = P[-1]
    P.append([Pprev[Pprev[node]] for node in range(n)])

marked = [[0] * n for _ in range(20)]

# marks [node, node + 2**bit] and returns number of newly marked nodes
def mark(bit, node):
    if marked[bit][node]:
        return 0
    marked[bit][node] = 1
    if bit:
        return mark(bit - 1, node) + mark(bit - 1, P[bit - 1][node])
    else:
        return 1

out = [0]
for i in range(m):
    v = V[i]
    a = (v + out[-1]) % n
    b = min(B[i], n)

    ans = 0
    for bit in range(20):
        if b & (1 << bit):
            ans += mark(bit, a)
            a = P[bit][a]
    out.append(ans)

out.pop(0)
print '\n'.join(str(x) for x in out)