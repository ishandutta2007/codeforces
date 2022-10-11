import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    n = m = inp[ii]; ii += 1
    g = inp[ii]; ii += 1
    b = inp[ii]; ii += 1
    
    good = n + 1 >> 1

    cycles, good = divmod(good - 1, g)
    good += 1

    n -= cycles * (g + b)
    n -= good
    if n <= 0:
        print cycles * (g + b) + good
        continue
    print m