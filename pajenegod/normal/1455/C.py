import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    x = inp[ii]; ii += 1
    y = inp[ii]; ii += 1

    if y == 0:
        print x,0
        continue

    if x == 0:
        print 0,y
        continue

    print x - 1, y