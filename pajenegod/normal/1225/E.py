import sys
range = xrange
input = raw_input
MOD = 10**9 + 7

inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
m = int(inp[ii]); ii += 1

matrix = []
for _ in range(n):
    matrix.append([+(c=='R') for c in inp[ii]]); ii += 1

xrook = [list(row) for row in matrix]
for y in range(n):
    for x in reversed(range(m - 1)):
        xrook[y][x] += xrook[y][x + 1]

yrook = [list(row) for row in matrix]
for y in reversed(range(n - 1)):
    for x in range(m):
        yrook[y][x] += yrook[y + 1][x]

xways = [[0]*m for _ in range(n)]
yways = [[0]*m for _ in range(n)]

for x in range(m):
    if xrook[-1][x] == 0:
        xways[-1][x] = 1
        yways[-1][x] = 1

sy = xways[-1][1:]
ystones = matrix[-1][:-1]
for x in range(m - 1):
    if ystones[x]:
        sy[x] = 0

for y in reversed(range(n - 1)):
    sx = 0
    xstones = 0
    for x in reversed(range(m)):
        sx = (sx + yways[y + 1][x]) % MOD
        xstones += matrix[y][x]
        if matrix[y][x]:
            sx = (sx - yways[y + 1][m - xstones]) % MOD
        xways[y][x] = sx

        if x < m - 1:
            sy[x] = (sy[x] + xways[y][x + 1]) % MOD
            ystones[x] += matrix[y][x]
            if matrix[y][x]:
                sy[x] = (sy[x] - xways[n - ystones[x]][x + 1]) % MOD
            yways[y][x] = sy[x]
        else:
            yways[y][x] = +(yrook[y][x] == 0)

print xways[0][0] % MOD