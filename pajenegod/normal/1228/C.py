import sys
range = xrange
input = raw_input

MOD = 10**9 + 7
MODm1 = MOD - 1

x,n = [int(x) for x in input().split()]

P = []
p = 2
while p * p <= x:
    if x % p == 0:
        P.append(p)
        while x % p == 0:
            x //= p
    p += 1
if x > 1:
    P.append(x)

prod = 1
for p in P:
    q = p
    while q <= n:
        prod = prod * pow(p,(n//q) % MODm1,MOD) % MOD
        q *= p

print prod