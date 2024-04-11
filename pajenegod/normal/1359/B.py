import sys
range = xrange

inp = sys.stdin.read().split()
ii = 0

t = int(inp[ii]); ii += 1
for _ in range(t):
    n,m,X,Y = [int(_) for _ in inp[ii: ii + 4]]; ii += 4
    A = []
    for _ in range(n):
        row = [+(c == '.') for c in inp[ii]]; ii += 1
        A.append(row)
    total = 0
    for y in range(n):
        for x in range(m):
            if A[y][x]:
                if x + 1 < m and A[y][x + 1]:
                    total += min(2 * X, Y)
                    A[y][x] = A[y][x + 1] = 0
                else:
                    total += X
                    A[y][x] = 0
    print total