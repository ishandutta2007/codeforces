import sys
range = xrange
input = raw_input
 
inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
xl = xr = inp[ii]; ii += 1

cost = 0
for _ in range(n):
    l = inp[ii]; ii += 1
    r = inp[ii]; ii += 1

    # overlap
    if (max(r, xr) - min(l, xl) + 1) < (xr - xl + 1) + (r - l + 1):
        xl, xr = max(l, xl), min(r, xr)
    elif r < xl:
        cost += xl - r
        xl, xr = r, xl
    else:
        cost += l - xr
        xl, xr = xr, l
print cost