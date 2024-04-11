import sys
range = xrange
input = raw_input

A = input()
print A+''.join(str(c) for c in reversed(A))