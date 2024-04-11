import sys
range = xrange
input = raw_input

inter = lambda: int(input())
inters = lambda: [int(x) for x in input().split()]

t = inter()
for _ in range(t):
    n,m,a,b = inters()
    A = [[0] * m for _ in range(n)]
    colcount = [0]*m
    rowcount = [0]*n
    tmp = 0
    for y in range(n):
        lastx = 0
        for x in range(m):
            truex = (x + tmp) % m
            if colcount[truex] < b and rowcount[y] < a:
                A[y][truex] += 1
                colcount[truex] += 1
                rowcount[y] += 1
                lastx = truex + 1
        tmp = lastx


    if all(c == b for c in colcount) and all(c == a for c in rowcount):
        print 'YES'
        print '\n'.join(''.join(str(x) for x in a) for a in A)
    else:
        print 'NO'