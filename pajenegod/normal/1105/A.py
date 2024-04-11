import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]

besta = 1000000000
T = -1
for t in range(1,101):
    s = 0
    for a in A:
        s += max(0,abs(a-t)-1)
    if s<besta:
        besta = s
        T = t
print T,besta