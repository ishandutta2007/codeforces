import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = inp[ii]; ii += 1
    m = inp[ii]; ii += 1
    if m == 0:
        out.append(0)
        continue

    dist, extra = divmod(n - m, m + 1)

    # full
    B = extra
    # less than full
    A = m + 1 - B

    ints1 = B * (B + 1)//2
    ints1 *= -(dist + 1 + 1)
    ints1 += (n + 1) * B
    ints1 *= dist + 1 + 1


    used = (dist + 1 + 1) * B
    ints2 = A * (A + 1)//2
    ints2 *= -(dist + 1)
    ints2 += (n + 1 - used) * A
    ints2 *= dist + 1

    out.append(ints1 + ints2)
print '\n'.join(str(x) for x in out)