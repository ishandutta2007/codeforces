import heapq
import sys
range = xrange
input = raw_input

BIG = 1e18

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

out = []
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1

    M = inp[ii    : ii + 2 * n: 2]
    P = inp[ii + 1: ii + 2 * n: 2]
    ii += 2 * n

    order = sorted(range(n), key = M.__getitem__, reverse = True)
    M = [M[i] for i in order]
    P = [float(P[i]) for i in order]

    ans = 0.0
    bought = 0
    Q = []
    for i in range(n):
        heapq.heappush(Q, P[i])
        if n - i - 1 + bought < M[i]:
            bought += 1
            ans += heapq.heappop(Q)
    out.append(ans)
print '\n'.join(str(int(x)) for x in out)