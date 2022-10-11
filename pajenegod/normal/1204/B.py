import sys
range = xrange
input = raw_input

n,l,r = [int(x) for x in input().split()]

smallest = sum(1 << i for i in range(l)) + n - l

largest = sum(1 << i for i in range(r)) + (1 << (r-1))*(n - r)

print smallest, largest