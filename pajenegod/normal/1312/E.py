import sys
range = xrange
input = raw_input
 
n = int(input())
A = [int(x) for x in input().split()]
 
DP = [[-1]*(n + 1) for i in range(n)]
for size in range(1, n + 1):
    for l in range(n - size + 1):
        r = l + size
        if size == 1:
            DP[l][size] = A[l]
        else:
            for mid in range(l,r):
                left = DP[l][mid - l]
                right = DP[mid][r - mid]
                if left == right >= 0:
                    DP[l][size] = left + 1
                    break
DP2 = [0]*(n + 1)
for l in reversed(range(n)):
    besta = n
    for size in range(1, n - l + 1):
        if DP[l][size] >= 0:
            besta = min(besta, 1 + DP2[l + size])
    DP2[l] = besta
print DP2[0]