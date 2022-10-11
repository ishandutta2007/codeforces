import sys
range = xrange
input = raw_input

orda = ord('a')

t = int(input())
for _ in range(t):
    n,a,b = [int(x) for x in input().split()]
    A = [0]*n
    for i in range(n):
        j = i % b % a
        A[i] = orda + j
    print ''.join(chr(a) for a in A)