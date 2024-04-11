import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

n = int(input())
A = [int(x) for x in input().split()]

big = 1000010
count = [0]*big
for a in A:
    count[a] += 1

P = []
small = [0] * big
for i in range(2, big):
    if not small[i]:
        small[i] = i
        P.append(i)
    j = 0
    while j < len(P) and P[j] <= small[i] and i * P[j] < big:
        small[i * P[j]] = P[j]
        j += 1

mu = [1]*big
for i in range(2, big):
    mu[i] = -mu[i // small[i]]
for p in P:
    j = p2 = p * p
    while j < big:
        mu[j] = 0
        j += p2

counter = [0]*big
for g in range(2, big):
    c = 0
    d = g
    while d < big:
        c += count[d]
        d += g
    if c > 0:
        counter[g] = int(c * pow(2, c - 1, MOD) % MOD)

ans = 0
for g in range(2, big):
    c = 0
    f = 1
    while f * g < big:
        c = (c + mu[f] * counter[f * g]) % MOD
        f += 1
    # c is number of subsequences with gcd = g
    ans = (ans + c * g) % MOD
print ans