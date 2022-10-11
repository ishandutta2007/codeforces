import sys
range = xrange
input = raw_input

MOD = 998244353 

n, m, k = [int(x) for x in input().split()]

if m == 1:
    print pow(n, k, MOD)
    sys.exit()

p = pow(m, MOD - 2, MOD)

vec = [0]*(k + 1)
vec[0] = 1
for i in range(k):
    for m in reversed(range(i + 1)):
        vec[m + 1] = int( (vec[m + 1] + (n - m) * vec[m]) % MOD )
        vec[m] = int(vec[m] * m % MOD)

x = p * pow(1 - p, MOD - 2, MOD)

summa = 0
for m in range(k + 1):
    summa += vec[m] * pow(1 + x, n - m, MOD) * pow(x, m, MOD) % MOD

summa *= pow(1 - p, n, MOD)

print summa % MOD