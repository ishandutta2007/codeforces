import sys
range = xrange
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    input()
    xa,ya = [int(x) for x in input().split()]
    xb,yb = [int(x) for x in input().split()]
    xc,yc = [int(x) for x in input().split()]

    if xa > xb or (xa == xb and ya > yb):
        xa,ya,xb,yb = xb,yb,xa,ya

    if ya == yb == yc and xa < xc < xb:
        cost = 2
    elif xa == xb == xc and ya < yc < yb:
        cost = 2
    else:
        cost = 0

    print abs(xa - xb) + abs(ya - yb) + cost