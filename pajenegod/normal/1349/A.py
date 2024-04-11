import sys
range = xrange
input = raw_input

big = 200010
primes = [0]*big
for i in range(2, big):
    if primes[i] == 0:
        primes[i] = i
        for j in range(2 * i, big, i):
            primes[j] = i

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
A = inp[ii: ii + n]; ii += n

counter = [0]*big
for a in A:
    while a > 1:
        p = primes[a]
        c = 1
        while a % p == 0:
            counter[p ** c] += 1
            a //= p
            c += 1

g = 1
for p in range(big):
    if primes[p] == p:
        i = 0
        while p ** (i + 1) < big and counter[p ** (i + 1)] >= n - 1:
            i += 1
        g *= p ** i
print g