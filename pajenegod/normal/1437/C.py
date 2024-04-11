import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    A.sort()

    big = 10**6

    DP = [[big] * (2 * n + 2) for _ in range(n + 1)]
    DP[-1] = [0] * (2 * n + 2)

    for i in range(n):
        a = A[i]
        DPi = DP[i]
        DPim1 = DP[i - 1]
        for t in range(1, 2 * n + 1):
            DPi[t] = min(DPi[t - 1], DPim1[t - 1] + abs(t - a))

    print min(DP[n - 1])