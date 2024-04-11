import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    odd = [(a - 1) & 1 for a in A[1::2]]
    even = [a & 1 for a in A[::2]]

    if sum(odd) != sum(even):
        print -1
    else:
        print sum(odd)