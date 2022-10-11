import sys
range = xrange
input = raw_input

def solve(a,b,n,m):
    if a + b < n + m:
        return False
    return min(a,b) >= m

t = int(input())
for _ in range(t):
    a,b,n,m = [int(x) for x in input().split()]
    print 'Yes' if solve(a,b,n,m) else 'No'