import sys
from collections import defaultdict as di
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

n = inp[ii]
ii += 1
A = []
for _ in range(n):
    A.append(inp[ii:ii + n])
    ii += n

d = di(lambda:len(d))
for y in range(n):
    for x in range(n): 
        for p in range(3):
            d[y,x,p]
m = len(d)

inf = 1000000000
large = 1000
mat = [[inf]*m for _ in range(m)]
for i in range(m):
    mat[i][i] = 0

for y in range(n):
    for x in range(n):
        for p in range(3):
            for q in range(p+1, 3):
                i = d[y,x,p]
                j = d[y,x,q]
                mat[i][j] = 1 + large
                mat[j][i] = 1 + large

# knight, bishop, rook
p = 0
for y in range(n):
    for x in range(n):
        i = d[y,x,p]
        for dy,dx in [(1,2),(2,1),(-1,2),(-2,1)]:
            x2 = x + dx
            y2 = y + dy
            if 0 <= x2 < n and 0 <= y2 < n:
                j = d[y2,x2,p]
                mat[i][j] = large
                mat[j][i] = large

p = 1
for y in range(n):
    for x in range(n):
        i = d[y,x,p]
        for dy,dx in [(1,1),(-1,1)]:
            y2 = y + dy
            x2 = x + dx
            while 0 <= x2 < n and 0 <= y2 < n:
                j = d[y2,x2,p]
                mat[i][j] = large
                mat[j][i] = large
                y2 += dy
                x2 += dx

p = 2
for y in range(n):
    for x in range(n):
        i = d[y,x,p]
        for dy,dx in [(0,1),(1,0)]:
            y2 = y + dy
            x2 = x + dx
            while 0 <= x2 < n and 0 <= y2 < n:
                j = d[y2,x2,p]
                mat[i][j] = large
                mat[j][i] = large
                y2 += dy
                x2 += dx

for k in range(m):
    for i in range(m):
        for j in range(m):
            if mat[i][k] + mat[k][j] < mat[i][j]:
                mat[i][j] = mat[i][k] + mat[k][j]

coords = [None]*(n**2)
for y in range(n):
    for x in range(n):
        coords[A[y][x] - 1] = (y,x)

best = [0,0,0]
for goal in range(1, n**2):
    y1,x1 = coords[goal - 1]
    y2,x2 = coords[goal]

    newbest = [inf,inf,inf]
    for p in range(3):
        for q in range(3):
            newbest[q] = min(newbest[q], best[p] + mat[d[y1,x1,p]][d[y2,x2,q]])
    best = newbest
ans = min(best)
print ans//large, ans%large