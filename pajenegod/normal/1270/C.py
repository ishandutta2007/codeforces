import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    A = inp[ii: ii + n]; ii += n

    extra = []
    if sum(A)&1:
        extra.append(1)
        A.append(1)

    xor = 0
    for a in A:
        xor ^= a
    extra.append(xor)
    A.append(xor)

    extra.append(sum(A))
    A.append(extra[-1])
    out.append(len(extra))
    out += extra

    xor = 0
    for a in A:
        xor ^= a
    assert(sum(A) == 2 * xor)
print ' '.join(str(x) for x in out)