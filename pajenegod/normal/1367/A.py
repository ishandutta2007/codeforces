import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    B = input()
    A = [B[0]]
    A += B[1::2]
    print ''.join(A)