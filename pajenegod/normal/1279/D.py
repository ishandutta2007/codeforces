import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1

MOD = 998244353

big = 10**6 + 10
counter = [0]*big
invcounter = [0]*big

for _ in range(n):
    k = inp[ii]; ii += 1
    kinv = pow(k, MOD - 2, MOD)
    for _ in range(k):
        a = inp[ii]; ii += 1
        counter[a] += 1
        invcounter[a] = (invcounter[a] + kinv) % MOD

ninv = pow(n, MOD - 2, MOD)

ans = 0
for a in range(big):
    c = counter[a] * ninv % MOD
    invc = invcounter[a] * ninv % MOD
    ans = (ans + c * invc)%MOD

print ans