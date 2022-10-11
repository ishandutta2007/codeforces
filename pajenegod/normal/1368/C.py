import sys
range = xrange
input = raw_input

A = [(0,0), (1,0), (0,1)]

out = []
n = int(input())
n += 1

for i in range(n):
    for x,y in A:
        out.append("%d %d" % (i + x, i + y))
out.append("%d %d" % (n, n))
print len(out)
print '\n'.join(out)