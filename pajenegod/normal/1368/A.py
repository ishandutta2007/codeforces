import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0
out = []

def sorter(p):
    return p if p[0] <= p[1] else (p[1], p[0])

t = inp[ii]; ii += 1
for _ in range(t):
    a,b,n = inp[ii: ii + 3]; ii += 3
    a,b = sorter((a,b))
    
    count = 0
    while b <= n:
        a += b
        a,b = sorter((a,b))
        count += 1
    print count