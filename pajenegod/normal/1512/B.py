import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = []
    for _ in range(n):
        A.append(list(input()))
    xmin = n
    xmax = 0
    ymin = n
    ymax = 0
    for i in range(n):
        for j in range(n):
            if A[i][j] == '*':
                xmin = min(j, xmin)
                xmax = max(j, xmax)
                ymin = min(i, ymin)
                ymax = max(i, ymax)
    if ymin == ymax:
        if ymax + 1 < n:
            ymax += 1
        else:
            ymin -= 1
    if xmin == xmax:
        if xmax + 1 < n:
            xmax += 1
        else:
            xmin -= 1

    for x,y in (xmin, ymin), (xmin, ymax), (xmax, ymin), (xmax, ymax):
        A[y][x] = '*'

    for a in A:
        print ''.join(a)