import sys
import bisect
range = xrange
input = raw_input

valid = []

big = 2 * 10**9 + 15
a = 1
while a * a <= big:
    b = max(a, a * a // 2 - 100)
    c = a * a - b
    while b < c:
        valc = c * c - c
        valb = b * b + b
        if valc == valb:
            if 1 <= a <= b <= c and a*a + b*b == c*c:
                valid.append(c)
            break
        b += 1
        c -= 1
    a += 1
valid.sort()

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1

    out.append(bisect.bisect_right(valid, n))

print '\n'.join(str(x) for x in out)