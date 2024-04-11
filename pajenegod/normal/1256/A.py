import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

q = inp[ii]; ii += 1
out = []
for _ in range(q):
    a = inp[ii]; ii += 1
    b = inp[ii]; ii += 1
    n = inp[ii]; ii += 1
    S = inp[ii]; ii += 1

    x = S//n
    y = S%n

    t = max(0, x - a)
    x -= t
    y += n * t

    if x <= a and y <= b:
        out.append('YES')
    else:
        out.append('NO')

print '\n'.join(str(x) for x in out)