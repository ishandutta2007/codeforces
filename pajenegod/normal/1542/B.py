import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n,a,b = inp[ii: ii + 3]; ii += 3

    powe = [1]
    while a != 1 and powe[-1] * a <= n:
        powe.append(powe[-1] * a)
    powe = [p % b for p in powe]

    if n % b in powe:
        out.append('Yes')
    else:
        out.append('No')

print '\n'.join(out)