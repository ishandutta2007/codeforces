import sys
range = xrange
input = raw_input

rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]

t = int(input())
for _ in range(t):
    n,k = rints()
    out = []
    if n & 1 == 0 and n >= 2 * k:
        m = n - 2 * k
        out = [n - 2 * k + 2] + [2] * (k - 1) 
    elif (n - k) & 1 == 0:
        out = [n - k + 1] + [1] * (k - 1)
    if out and all(x > 0 for x in out):
        print 'YES'
        print ' '.join(str(x) for x in out)
    else:
        print 'NO'