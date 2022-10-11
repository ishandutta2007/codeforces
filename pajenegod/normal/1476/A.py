import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,k = [int(x) for x in input().split()]
    
    m = (n + k - 1) // k * k
    print (n + m - 1) // n