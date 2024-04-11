import sys
range = xrange
input = raw_input

A = []

for c in map(int, '123456789'):
    x = c
    while x < 10**9:
        A.append(x)
        x = 10 * x + c

t = int(input())
for _ in range(t):
    n = int(input())
    print sum(1 for a in A if a <= n)