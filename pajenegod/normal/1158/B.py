import sys
range = xrange
input = raw_input

n,k = [int(x) for x in input().split()]

s = '0'*((n - k)//2) + '1'

print (s * ((n + len(s) - 1) // len(s))) [:n]