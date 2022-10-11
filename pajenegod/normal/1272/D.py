import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

DP = [[-1]*n for _ in range(2)]
for i in range(n):
    if i >= 1 and A[i - 1] < A[i]:
        DP[0][i] = 1 + DP[0][i - 1]
        DP[1][i] = 1 + DP[1][i - 1]
    else:
        DP[0][i] = 1
        DP[1][i] = 1

    if i >= 2 and A[i - 2] < A[i]:
        DP[1][i] = max(DP[1][i], 1 + DP[0][i - 2])

print max(max(DP[0]), max(DP[1]))