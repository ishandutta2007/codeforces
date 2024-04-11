from collections import Counter
import sys
range = xrange
input = raw_input

n = int(input())
A = Counter([input()[0] for _ in range(n)])

r = 0

def pair(x):
    return x*(x-1)//2

for c in A:
    x = A[c]
    y = x // 2
    r += pair(y) + pair(x - y)

print r