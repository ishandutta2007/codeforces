import sys
range = xrange
input = raw_input

MOD = 998244353

n,m,alpha = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

ways = 1
prev = 0
for b in B:
    block = b - prev
    waysblock = pow(alpha, block, MOD)
    total = waysblock * (waysblock + 1) * (MOD + 1 >> 1) % MOD
    ways = ways * total % MOD
    
    prev = b

lastblock = n - 2 * prev
waysblock = pow(alpha, lastblock, MOD)
total = waysblock % MOD
ways = ways * total % MOD

print ways