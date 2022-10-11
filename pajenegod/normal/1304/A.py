import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x,y,a,b = [int(x) for x in input().split()]
    
    l = 0
    r = 10**18
    while l < r:
        mid = l + r + 1 >> 1
        if x + a * mid <= y - b * mid:
            l = mid
        else:
            r = mid - 1
    if x + a * l == y - b * l:
        print l
    else:
        print -1