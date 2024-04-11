import sys
range = xrange
input = raw_input

inp = sys.stdin.read().split(); ii = 0

n = int(inp[ii]); ii += 1
m = int(inp[ii]); ii += 1

mat = []
for _ in range(n):
    s = inp[ii]; ii += 1
    for c in s:
        mat.append(+(c=='#'))

comp = 0
nfound = list(mat)
for y in range(n):
    for x in range(m):
        ind = y * m + x
        if not nfound[ind]:
            continue
        bfs = [ind]
        nfound[ind] = 0
        for ind in bfs:
            y,x = divmod(ind, m)
            if y and nfound[ind - m]:
                nfound[ind - m] = 0
                bfs.append(ind - m)
            if y + 1 < n and nfound[ind + m]:
                nfound[ind + m] = 0
                bfs.append(ind + m)
            if x and nfound[ind - 1]:
                nfound[ind - 1] = 0
                bfs.append(ind - 1)
            if x + 1 < m and nfound[ind + 1]:
                nfound[ind + 1] = 0
                bfs.append(ind + 1)
        comp += 1

rows = 0
for y in range(n):
    tmp = 0
    for x in range(m):
        tmp += mat[y * m + x] if x == 0 else +(not mat[y * m + x - 1] and mat[y * m + x])
    if tmp > 1:
        print -1
        sys.exit()
    rows += tmp

cols = 0
for x in range(m):
    tmp = 0
    for y in range(n):
        tmp += mat[y * m + x] if y == 0 else +(not mat[(y - 1) * m + x] and mat[y * m + x])
    if tmp > 1:
        print -1
        sys.exit()
    cols += tmp

if (rows == n and cols == m) or (rows < n and cols < m):
    print comp
else:
    print -1