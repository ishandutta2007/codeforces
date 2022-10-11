import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

q = int(inp[ii]); ii += 1

out = []
for _ in range(q):
    n = int(inp[ii]); ii += 1
    A = [i < '3' for i in inp[ii] + inp[ii + 1]]; ii += 2
    x = 0
    y = 0
    while True:
        while x < n and A[x + y*n]:
            x += 1
        if x == n:
            break
        y ^= 1
        if A[x + y*n]:
            break
        x += 1
    if y == 1 and x == n:
        out.append('YES')
    else:
        out.append('NO')
print '\n'.join(out)