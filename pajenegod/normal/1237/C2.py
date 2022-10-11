import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
n = inp[ii]; ii += 1

X = inp[ii    :ii + 3 * n: 3]
Y = inp[ii + 1:ii + 3 * n: 3]
Z = inp[ii + 2:ii + 3 * n: 3]

xmapper = {}
for x in sorted(X):
    if x not in xmapper:
        xmapper[x] = len(xmapper)

m = len(xmapper)
buckets = [[] for _ in range(m)]
for i in range(n):
    buckets[xmapper[X[i]]].append(i)


j = -1
pair = []
for b in buckets:
    ymapper = {}
    for y in sorted(Y[i] for i in b):
        if y not in ymapper:
            ymapper[y] = len(ymapper)

    k = len(ymapper)
    ybuckets = [[] for _ in range(k)]
    for i in b:
        ybuckets[ymapper[Y[i]]].append(i)

    i = -1
    for by in ybuckets:
        by.sort(key = Z.__getitem__)

        while len(by) >= 2:
            pair.append(by.pop())
            pair.append(by.pop())
        if by:
            if i == -1:
                i = by.pop()
            else:
                pair.append(i)
                pair.append(by.pop())
                i = -1
    if i != -1:
        if j == -1:
            j = i
        else:
            pair.append(i)
            pair.append(j)
            j = -1

out = []
for i in range(n//2):
    out.append('%d %d' % (pair[2 * i] + 1, pair[2 * i + 1] + 1))
print '\n'.join(out)