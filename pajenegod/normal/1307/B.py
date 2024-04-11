import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    n = inp[ii]; ii += 1
    x = inp[ii]; ii += 1

    A = inp[ii: ii + n]; ii += n
    if x in A:
        print 1
        continue

    Amax = max(A)
    print max((x + Amax - 1)//Amax, 2)