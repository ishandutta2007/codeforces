import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
m = inp[ii]; ii += 1

A = [[] for _ in range(m)]
for i in range(n):
    for j in range(m):
        A[j].append(inp[ii] - 1); ii += 1

s = 0
for j in range(m):
    cycle = [0]*n
    a = A[j]
    for i in range(n):
        if a[i] < n*m and (a[i] - j) % m == 0:
            cycle[a[i]//m - i] += 1
    mini = 10**9
    for i in range(n):
        val = n - cycle[i] + (n - i if i > 0 else 0)
        if val < mini:
            mini = val
    s += mini
print s