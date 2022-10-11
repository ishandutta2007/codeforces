import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

A = [int(x) for x in sys.stdin.read().strip()]; ii = 0
n = len(A)

def f(n):
    return (n * (n + 1) >> 1)

pow10 = [1]
for i in range(n):
    pow10.append(pow10[-1] * 10 % MOD)

cumsum = [0]
for i in range(n):
    cumsum.append((cumsum[-1] + (i + 1) * pow10[i]) % MOD)

s = 0
for i in range(n):
    m = n - 1 - i
    s += A[i] * pow10[m] * f(i)
    s += A[i] * cumsum[m]
    s %= MOD

print s % MOD