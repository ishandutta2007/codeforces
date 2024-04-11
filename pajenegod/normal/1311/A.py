import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    a = inp[ii]; ii += 1
    b = inp[ii]; ii += 1

    a -= b

    if a == 0:
        print 0
    elif (a < 0 and a & 1) or (a > 0 and a & 1 == 0):
        print 1
    else:
        print 2