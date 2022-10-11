import sys

big = 10**6 + 1
P = [1] * big
P[0] = P[1] = 0
for i in range(2, big):
    if P[i]:
        for j in range(2 * i, big, i):
            P[j] = 0


mobius = [1] * big
mobius[0] = 0
for i in range(1, big):
    if P[i]:
        mobius[i] *= -1
        for j in range(2 * i, big, i):
            mobius[j] *= -1
        for j in range(i * i, big, i * i):
            mobius[j] = 0


def any_coprime(A):
    n = len(A)
    m = max(A) + 1
    marked = [0] * m
    for a in A:
        marked[a] = 1

    s = 0
    for d in range(2, m):
        count = 0
        for j in range(d, m, d):
            count += marked[j]

        s += mobius[d] * (count * (count - 1) // 2)
        
    return -s != n * (n - 1) // 2

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
A = inp[ii: ii + n]; ii += n

marked = [0] * big
for a in A:
    marked[a] = 1

for gcd in reversed(range(1, big)):
    if marked[gcd]:
        continue

    A = []
    for j in range(gcd, big, gcd):
        if marked[j]:
            A.append(j // gcd)

    if A and any_coprime(A):
        marked[gcd] = 1

print(sum(marked) - n)