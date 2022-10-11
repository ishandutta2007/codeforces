import sys
range = xrange
input = raw_input

b,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

par = 0
base = 1
for a in reversed(A):
    par = (par + a*base)%2
    base=base*b%2
if par:
    print 'odd'
else:
    print 'even'