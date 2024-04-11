import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    a,b,c = sorted(int(x) for x in input().split())
    print(a+b+c-1)