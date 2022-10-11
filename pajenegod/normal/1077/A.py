import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,k = [int(x) for x in input().split()]
    r = (k+1)//2
    l = k//2
    print a*r-b*l