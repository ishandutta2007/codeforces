import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,r = [int(x) for x in input().split()]
    
    ans = 0
    upper = min(r + 1, n)
    ans += upper * (upper - 1) >> 1
    #for k in range(1, min(r + 1, n)):
    #    #if n >= k + 1:
    #    ans += k
    if n <= r:
        ans += 1
    print ans