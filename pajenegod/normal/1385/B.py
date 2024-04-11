import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) - 1 for x in input().split()]
    seen = [0]*n
    B = []
    for a in A:
        if not seen[a]:
            seen[a] = 1
            B.append(a)
    print ' '.join(str(x + 1) for x in B)