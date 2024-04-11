import sys
range = xrange
input = raw_input

magic = (3 * 4 * 5) ** 3
tmagic = magic * 5

DP = [0] * (2 * magic + 5)
for i in range(1, 2 * magic):
    DP[i] = min(DP[i - 3] + 15, DP[i - 4] + 20, DP[i - 5] + 25)

t = int(input())
for _ in range(t):
    n = int(input())

    if n & 1:
        n += 1

    n //= 2
    if n <= magic:
        cost = DP[n]
    else:
        cost = tmagic * ((n - magic) // magic) + DP[(n - magic) % magic + magic]

    print cost