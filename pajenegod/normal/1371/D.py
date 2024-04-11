import sys
range = xrange
input = raw_input

out = []
t = int(input())
for _ in range(t):
    n, k = [int(x) for x in input().split()]

    mat = [[0] * n for _ in range(n)]
    i = 0
    while k:
        y,x = divmod(i, n)
        mat[y][x] = 1
        k -= 1
        i += n + 1
        if i >= n * n:
            i -= n * n
    R = [0]*n
    C = [0]*n
    for y in range(n):
        for x in range(n):
            R[y] += mat[y][x]
            C[x] += mat[y][x]
    
    out.append(str((max(R) - min(R)) ** 2 + (max(C) - min(C)) ** 2))
    for row in mat:
        out.append(''.join(str(x) for x in row))
print '\n'.join(out)