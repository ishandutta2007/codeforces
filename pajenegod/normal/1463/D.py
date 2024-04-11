import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1

for _ in range(t):
    n = inp[ii]; ii += 1
    B = inp[ii:ii + n]; ii += n

    Bset = set(B)
    notB = [i for i in range(1, 2 * n + 1) if i not in Bset]

    minx = 0
    j = 0
    for b in B:
        while j < n and notB[j] < b:
            j += 1
        minx += j < n
        j += 1

    maxx = 0
    j = 0
    for b in reversed(B):
        while j < n and notB[~j] > b:
            j += 1
        maxx += j < n
        j += 1

    l = n - maxx
    r = minx
    print r - l + 1