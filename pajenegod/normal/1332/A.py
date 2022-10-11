import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c,d = [int(x) for x in input().split()]
    x,y,x1,y1,x2,y2 = [int(x) for x in input().split()]

    canx = x1 != x2
    cany = y1 != y2

    dx = b - a
    dy = d - c

    if (x1 <= x + dx <= x2 and  
       y1 <= y + dy <= y2 and
       x1 <= x <= x2 and
       y1 <= y <= y2 and
       (canx or (a == 0 and b == 0)) and
       (cany or (c == 0 and d == 0))
       ):
        print 'Yes'
    else:
        print 'No'