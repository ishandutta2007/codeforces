import sys
import random
range = xrange
input = raw_input

q = int(input())
for _ in range(q):
    l1,r1,l2,r2 = [int(x) for x in input().split()]
    
    a = b = 0
    while a==b:
        a = random.randint(l1,r1)
        b = random.randint(l2,r2)
    print a,b