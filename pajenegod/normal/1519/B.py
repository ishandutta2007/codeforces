import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,m,k = [int(x) for x in input().split()]

    if n < m:
        n,m = m,n

    if (n - 1) + (m - 1) * n <= k <= (m - 1) + (n - 1) * m:
        print 'YES'
    else:
        print 'NO'