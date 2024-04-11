import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    B = [a for a in A if a]
    C = [a for a in A if not a]

    if len(B) > n//2:
        if len(B) & 1:
            B.pop()

        print len(B)
        print ' '.join(str(b) for b in B)
    else:
        print len(C)
        print ' '.join(str(b) for b in C)