import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    l = inp[ii]; ii += 1
    r = inp[ii]; ii += 1

    count = 0
    while l < r:
        count += r - l
        r //= 10
        l //= 10
    print count