import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n,x = [int(x) for x in input().split()]
    A = [int(a) for a in input().split()]

    A.sort(reverse = True)
    i = 0
    s = 0
    while i < n:
        s += A[i]
        if s < x * (i + 1):
            break
        i += 1
    print i