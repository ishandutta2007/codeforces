import sys
range = xrange
input = raw_input

ord0 = ord('0')
inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
m = int(inp[ii]); ii += 1
t = int(inp[ii]); ii += 1

mat = []
for _ in range(n):
    S = inp[ii]; ii += 1
    for c in S:
        mat.append(ord(c) - ord0)

bfs = []
state = [-1]*(n*m)
for i in range(n*m):
    b = mat[i]
    y,x = divmod(i, m)
    if (x and mat[i - 1] == b) or (x + 1 < m and mat[i + 1] == b) or (y and mat[i - m] == b) or (y + 1 < n and mat[i + m] == b):
        bfs.append(i)
        state[i] = 0

for i in bfs:
    b = mat[i]
    d = state[i] + 1
    y,x = divmod(i, m)
    if x and mat[i - 1] != b and state[i - 1] == -1:
        state[i - 1] = d
        bfs.append(i - 1)
    if x + 1 < m and mat[i + 1] != b and state[i + 1] == -1:
        state[i + 1] = d
        bfs.append(i + 1)
    
    if y and mat[i - m] != b and state[i - m] == -1:
        state[i - m] = d
        bfs.append(i - m)
    if y + 1 < n and mat[i + m] != b and state[i + m] == -1:
        state[i + m] = d
        bfs.append(i + m)

out = []
for _ in range(t):
    y = int(inp[ii]) - 1; ii += 1
    x = int(inp[ii]) - 1; ii += 1
    p = int(inp[ii]); ii += 1

    i = y * m + x
    if 0 <= state[i] < p:
        out.append(mat[i] ^ int(1 & (p - state[i])))
    else:
        out.append(mat[i])
print '\n'.join(str(x) for x in out)