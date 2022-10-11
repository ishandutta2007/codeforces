import sys
range = xrange
input = raw_input

def solve(x,y,a,b,goal):
    x -= a * goal
    y -= b * goal
    
    diff = b - a

    if diff == 0:
        return x >= 0 and y >= 0

    ycount = 0
    if y < 0:
        ycount = (-y) // diff
        x -= diff * ycount
        y += diff * ycount
    
    while y < 0:
        x -= diff
        y += diff
        ycount += 1
    
    return x >= 0 and y >= 0 and ycount <= goal


inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    x,y,a,b = inp[ii: ii + 4]; ii += 4
    if a > b:
        x,y,a,b = y,x,b,a

    l = 0
    r = 10**9 + 10
    while l < r:
        m = l + r + 1 >> 1
        if solve(x,y,a,b,m):
            l = m
        else:
            r = m - 1
    
    print l