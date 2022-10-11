import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    s = sum(A)
    if s == n:
        cost = 0
    elif s > n:
        cost = s - n
    else:
        cost = 1

    print cost