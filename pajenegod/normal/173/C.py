import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
A = []
for _ in range(n):
    A.append([int(x) for x in input().split()])

B = [[0] * (m + 1) for _ in range(n + 1)]

for i in range(n):
    for j in range(m):
        B[i + 1][j + 1] = B[i + 1][j] + B[i][j + 1] - B[i][j] + A[i][j]

def getsum(i1,j1,i2,j2):
    return B[i2][j2] - B[i2][j1] - B[i1][j2] + B[i1][j1]

const = min(n, m) // 2 + 3

DP = [[0]*m for _ in range(n)]
for i in range(n):
    for j in range(m):
        DP[i][j] = A[i][j]

maxi = -10**9
for layer in range(1, const):
    for i in range(n):
        for j in range(m):
            endy = i + 2 * layer + 1
            endx = j + 2 * layer + 1
            if endy > n or endx > m:
                break
            x = DP[i][j] = getsum(i,j,endy, endx) - A[i + 1][j] - DP[i + 1][j + 1]
            maxi = max(x, maxi)
print maxi