import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

q = inp[ii]; ii += 1
x = inp[ii]; ii += 1

counter = [0]*x
pos = 0

out = []
for _ in range(q):
    y = inp[ii]; ii += 1
    counter[y%x] += 1
    while counter[pos % x] >= (pos // x) + 1:
        pos += 1
    out.append(pos)
print '\n'.join(str(x) for x in out)