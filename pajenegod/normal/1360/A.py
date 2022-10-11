import sys
range = xrange
input = raw_input

inter = lambda: int(input())
inters = lambda: [int(x) for x in input().split()]

t = inter()
for _ in range(t):
    a,b = inters()
    print max(max(a,b), 2 * min(a, b))**2