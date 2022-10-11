import sys
range = xrange
input = raw_input

big = 4 * 10**4

P = [0] * big
for i in range(2, big):
    if P[i] == 0:
        for j in range(i, big, i):
            P[j] = i

primes = [p for p in range(2, big) if P[p] == p]

t = int(input())
for _ in range(t):
    n = int(input())

    depth = {n:0}
    bfs = [n]

    for numb in bfs:
        if numb == 1:
            break

        if numb - 1 not in depth:
            depth[numb - 1] = depth[numb] + 1
            bfs.append(numb - 1)
        for p in primes:
            if p * p > numb:
                break
            if numb % p == 0:
                if p not in depth:
                    depth[p] = depth[numb] + 1
                    bfs.append(p)
    print depth[1]