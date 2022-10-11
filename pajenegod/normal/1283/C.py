import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
F = [x - 1 for x in inp[ii: ii + n]]; ii += n

given = [-1]*n
for f in F:
    if f >= 0:
        given[f] = 1

giv = []
for i in range(n):
    if F[i] < 0:
        giv.append(i)

rec = []
for i in reversed(range(n)):
    if given[i] < 0:
        rec.append(i)

for i in range(len(giv)):
    F[giv[i]] = rec[i]

for i in range(n):
    if F[i] == i:
        j = 0
        while giv[j] == i:
            j += 1
        g = giv[j]
        F[i], F[g] = F[g],F[i]

print ' '.join(str(x + 1) for x in F)