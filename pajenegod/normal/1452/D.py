import sys
range = xrange
input = raw_input

n = int(input())

MOD = 998244353 

fib = [0,1,1]
for i in range(len(fib), n + 1):
    fib.append((fib[-1] + fib[-2]) % MOD)

print fib[n] * pow(pow(2, n, MOD), MOD - 2, MOD) % MOD