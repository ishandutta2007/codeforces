import sys
range = xrange
big = 500001
A = [0]*big
small = 500
buckets = [[0]*i for i in range(1, small + 1)]

def add(x,y):
    for i,b in enumerate(buckets):
        b[x%(i+1)] += y

def summa(x,i):
    s = 0
    while i < big:
        s += A[i]
        i += x
    return s

inp = [int(x) for x in sys.stdin.read().split()]
ii = 0

q = inp[ii]
ii += 1
out = []
for _ in range(q):
    c = inp[ii]
    ii += 1
    x = inp[ii]
    ii += 1
    y = inp[ii]
    ii += 1
    if c == 1:
        A[x] += y
        add(x,y)
    else:
        s = buckets[x - 1][y] if x<=small else summa(x,y)
        out.append(s)
print '\n'.join(str(x) for x in out)