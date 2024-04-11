import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

oddA = sum(1 for a in A if a&1)
evenA = n-oddA
oddB = sum(1 for a in B if a&1)
evenB = m - oddB

print min(oddA,evenB) + min(oddB,evenA)