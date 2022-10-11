import sys
range = xrange
input = raw_input

out = []
t = int(input())
for _ in range(t):
    n,m = [int(x) for x in input().split()]
    out.append('W' + 'B'*(m - 1))
    for _ in range(n - 1):
        out.append('B'*m)
print '\n'.join(out)