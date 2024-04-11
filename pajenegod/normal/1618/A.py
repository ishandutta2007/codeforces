import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    B = [int(x) for x in input().split()]
    B.sort()

    A = [B.pop(0)]
    while len(B) > 1:
        b = B.pop(0)
        for a in A:
            B.remove(a + b)
        A.append(b)
    print ' '.join(str(x) for x in A)