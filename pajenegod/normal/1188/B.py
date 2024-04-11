import sys
from collections import defaultdict as di
range = xrange
input = raw_input

n,p,k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

found = di(int)
count = 0
for a in A:
    my = int((pow(a,4,p) - k * a)%p)
    count += found[my]
    found[my] += 1
    
print count