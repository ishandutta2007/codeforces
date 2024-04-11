import sys
range = xrange
input = raw_input

n,m,k = [int(x) for x in input().split()]

A = []
for _ in range(n):
    A.append([int(x) for x in input().split()])

big = 10**9
B = [-big] * k
B[0] = 0
for i in range(n):
    DP = [[-big] * (m // 2 + 1) for _ in range(k)]
    DP[0] = [0] * (m // 2 + 1)

    for j in range(m):
        a = A[i][j]
        for x in reversed(range(m//2)):
            for kk in range(k):
                DP[(kk + a) % k][x + 1] = max(DP[kk][x] + a, DP[(kk + a) % k][x + 1])

    C = [-big] * k
    for kk1 in range(k):
        for kk2 in range(k):
            ind = (kk1 + kk2) % k
            for x in range(m//2 + 1):
                C[ind] = max(C[ind], B[kk1] + DP[kk2][x])
    B = C

print B[0]