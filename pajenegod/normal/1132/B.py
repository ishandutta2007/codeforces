import sys,__pypy__
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]
m = int(input())
Q = [int(x) for x in input().split()]

A.sort()
out = __pypy__.builders.StringBuilder()
Asum = sum(A)
for q in Q:
    out.append(str(Asum-A[-q]))
    out.append('\n')
sys.stdout.write(out.build())