import sys
range = xrange
input = raw_input

rint = lambda: int(input())
rints = lambda: [int(x) for x in input().split()]

t = int(input())
for _ in range(t):
    n0,n1,n2 = rints()
    ans = []
    if n1 or n0:
        ans = [0] * (n0 + 1)
    if n1 or n2:
        ans += [1]*(n2 + 1)
    if n1:
        n1 -= 1
        ans += ([0,1]*(n1))[:n1]
    print ''.join(str(x) for x in ans)