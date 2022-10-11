import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b = [int(x) for x in input().split()]
    a = min(a, 2 * b)
    b = min(b, 2 * a)
    e = (a + b) // 3
    print e