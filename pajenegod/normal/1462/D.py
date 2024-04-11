import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii : ii + n]; ii += n

    cand = [A[0]]
    for i in range(1,n):
        cand.append(cand[-1] + A[i])
    s = cand[-1]

    finder = set(cand)
    for d in cand:
        if s % d == 0 and all(j * d in finder for j in range(1, s//d + 1)):
            print n - s//d
            break