import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]

    B = sorted(set(A))
    Bused = set(A)
    for a in A:
        if a in Bused:
            Bused.remove(a)
        else:
            B.append(a)
    print ' '.join(str(x) for x in B)