import sys
range = xrange
input = raw_input

MOD = 998244353

n,m = [int(x) for x in input().split()]

if n == 2:
    print 0
    sys.exit()

k = n - 2
big = 3 * 10**5
choose = [0] * big
choose[k] = 1
for i in range(k + 1, big):
    choose[i] = choose[i - 1] * i * pow(i - k, MOD - 2, MOD) % MOD

s = 0
for maxval in range(n - 1, m + 1):
    s = (s + choose[maxval - 1] * pow(2, n - 3, MOD) * (n - 2)) % MOD
print s