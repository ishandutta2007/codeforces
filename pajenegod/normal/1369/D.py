import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

def marker(i):
    if i <= 3:
        return 0
    if i == 4:
        return 1
    return [0,1,1][(i - 5) % 3]

big = 2 * 10**6 + 10
ways = [0]*(big + 10)

ways[3] = 1
for i in range(4, big):
    x = 4 * ways[i - 4] + 4 * ways[i - 3] + ways[i - 2] + 1
    y = 2 * ways[i - 2] + ways[i - 1]
    if marker(i):
        ans = x % MOD
    else:
        ans = y % MOD
    ways[i] = ans

t = int(input())
for _ in range(t):
    n = int(input())
    print 4 * ways[n] % MOD