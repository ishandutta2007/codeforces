import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a, b  = [int(x) for x in input().split()]

    print (b - (a % b)) % b