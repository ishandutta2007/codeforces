import sys
range = xrange
input = raw_input

a,b,c = [int(x) for x in input().split()]


k = 0

x = min(a,b)
c += x
a -= x
b -= x

k += 2*c + (1 if b else 0) + (1 if a else 0)
print k