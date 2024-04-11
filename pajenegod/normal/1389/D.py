import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    k = inp[ii]; ii += 1

    l1 = inp[ii]; ii += 1
    r1 = inp[ii]; ii += 1

    l2 = inp[ii]; ii += 1
    r2 = inp[ii]; ii += 1

    if l2 < l1 or (l1 == l2 and r2 < r1):
        l1,r1,l2,r2 = l2,r2,l1,r1

    if r1 <= l2:
        base = l2 - r1
        inter = 0
    else:
        base = 0
        inter = min(r1,r2) - max(l1,l2)
    k -= inter * n
    left = (r2-l2) + (r1-l1) + base - 2 * inter

    if k <= 0:
        out.append(0)
        continue
    best = -1
    for i in range(1, n + 1):
        tmp = base * i

        x = min(i * left, k)
        y = k - x
        tmp += x + 2 * y
        if best == -1 or best > tmp:
            best = tmp
    out.append(best)

print '\n'.join(str(x) for x in out)