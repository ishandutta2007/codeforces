import sys
range = xrange
input = raw_input

n = int(input())
A = [int(input()) for _ in range(n)]

par = 0
for a in A:
    if a & 1:
        print (a + par)//2
        par ^= 1
    else:
        print a//2