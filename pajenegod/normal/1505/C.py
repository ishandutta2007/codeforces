import sys
range = xrange
input = raw_input

A = input()
B = [ord(c) - ord('A') for c in A]

n = len(A)

C = [B[i - 2] + B[i - 1] - B[i] for i in range(2,n)]

print 'YES' if all(c % 26 == 0 for c in C) else 'NO'