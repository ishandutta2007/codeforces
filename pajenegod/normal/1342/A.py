import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    x,y = [int(x) for x in input().split()]
    a,b = [int(_) for _ in input().split()]
    
    val = min(x,y) * min(2*a, b) + abs(x - y) * a
    print val