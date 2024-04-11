import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    
    total = 2**n
    for i in range(n//2 - 1):
        total += 2**(i + 1)

    other = 0
    for i in range(n//2, n):
        other += 2**i
    print abs(total - other)