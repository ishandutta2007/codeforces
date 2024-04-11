
import sys, os
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

mark = [0]*8001
t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n
    for i in range(n + 1):
        mark[i] = 0
    cumsum = [0]
    for a in A:
        cumsum.append(cumsum[-1] + a)
    for l in range(n):
        cumsuml = cumsum[l]
        for r in range(l + 2, n + 1):
            if cumsum[r] - cumsuml <= n:
                mark[cumsum[r] - cumsuml] = 1
    ans = 0
    for a in A:
        ans += mark[a]
    out.append(ans)
os.write(1, '\n'.join(str(x) for x in out))