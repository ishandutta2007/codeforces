import sys

inp = sys.stdin.read().split(); ii = 0
t = int(inp[ii]); ii += 1
for _ in range(t):
    n = int(inp[ii]); ii += 1
    mat = []
    for _ in range(n):
        mat.append([+(c == '1') for c in inp[ii]]); ii += 1

    sums = [0] * n
    for diag in range(n):
        for i in range(n):
            j = (i + diag) % n
            sums[diag] += mat[i][j]

    best = n * n
    for diag in range(n):
        s = sums[diag]
        best = min(best, (n - s) + (sum(sums) - s))

    print best