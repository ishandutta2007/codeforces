import sys
range = xrange
input = raw_input

big = 10**7 + 10
primes = [1]*big
for i in range(2, big):
    if primes[i] == 1:
        for j in range(i, big, i):
            primes[j] = i

n = int(input())
A = [int(x) for x in input().split()]

out0 = []
out1 = []
for a in A:
    if a & 1:
        p = primes[a]
    else:
        p = 2
    
    if p == 1:
        p = q = -1
    else:
        while a % p == 0:
            a //= p
        q = a
        if q == 1:
            p = q = -1
    
    out0.append(p)
    out1.append(q)

print ' '.join(str(x) for x in out0)
print ' '.join(str(x) for x in out1)