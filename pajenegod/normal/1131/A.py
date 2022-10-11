import sys
range = xrange
input = raw_input

w1,h1,w2,h2 = [int(x) for x in input().split()]

#w1>=w2
ans = 2*h1+w1 + w2 + 2*h2 + 4 + (w1-w2)
print ans