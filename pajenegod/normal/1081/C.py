import sys
range = xrange
input = raw_input

MOD = 998244353

n,m,k = [int(x) for x in input().split()]

ways = [0]*n
ways[0] = m

for i in range(1,n):
    for j in reversed(range(1,n)):
        ways[j] = (ways[j]+(m-1)*ways[j-1])%MOD

print ways[k]%MOD