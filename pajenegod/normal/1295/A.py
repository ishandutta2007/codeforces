import sys
range = xrange
input = raw_input
MOD = 998244353

t = int(input())
for _ in range(t):
    n = int(input())

    ans = '7' if n & 1 else ''
    ans += '1' * ((n - 3 * (n & 1))//2)

    print ans