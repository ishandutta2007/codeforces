import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
        n = inp[ii]; ii += 1
        k = inp[ii]; ii += 1

        a,left = divmod(n,k)
        left = min(left, k//2)
        out.append(a*k + left)

print '\n'.join(str(x) for x in out)