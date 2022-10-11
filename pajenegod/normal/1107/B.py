import sys
range = xrange
input = raw_input

n = int(input())

for _ in range(n):
    k,x = [int(x) for x in input().split()]
    print x+9*(k-1)