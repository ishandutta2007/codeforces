import sys
range = xrange
input = raw_input

def gcd(a,b):
    while a:
        a,b = b%a, a
    return b

def lcm(a,b):
    return (a // gcd(a,b)) * b

n,m = [int(x) for x in input().split()]
if n == m == 1:
    print 0
    sys.exit()

if m < n:
    dx = 0
    dy = m
else:
    dx = n
    dy = 0

A = [[0]*m for _ in range(n)]
for i in range(n):
    Ai = A[i]
    for j in range(m):
        x = j + 1 + dx
        y = i + 1 + dy
        Ai[j] = lcm(x,y)

print '\n'.join(' '.join(str(x) for x in row) for row in A)