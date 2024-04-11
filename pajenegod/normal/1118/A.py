import sys
range = xrange
input = raw_input

q = int(input())
for _ in range(q):
    n,a,b = [int(x) for x in input().split()]
    cost = a if n&1 else 0
    cost += min(a*2,b)*(n//2)
    print cost