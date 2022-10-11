import sys
from collections import defaultdict
range = xrange
input = raw_input

big = 10**5
P = [0] * big
for i in range(2, big):
    if P[i] == 0:
        for j in range(i, big, i):
            P[j] = i

primes = [p for p in range(2, big) if P[p] == p]

t = int(input())
for _ in range(t):
    n = int(input())
    
    counter = []
    for p in primes:
        count = 0
        while n % p == 0:
            n //= p
            count += 1

        if count:
            counter.append((p, count))
    if n > 1:
        counter.append((n, 1))

    maxcount = max(c for p,c in counter)

    A = [1] * maxcount
    for p,c in counter:
        for j in range(c):
            A[~j] *= p

    print len(A)
    print ' '.join(str(x) for x in A)