import sys
range = xrange
input = raw_input

n = int(input())
C = [c for c in input()]
C.sort()
print ''.join(C)