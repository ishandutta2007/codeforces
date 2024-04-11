import sys
range = xrange
input = raw_input

big = 2 * 10 ** 5 + 100

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    counter = [0] * big
    for a in A:
        counter[a] += 1

    DP = counter[:]
    for i in reversed(range(1, big)):
        best = 0
        j = 2
        while i * j < big:
            best = max(DP[i * j], best)
            j += 1

        DP[i] += best
    print n - DP[1]