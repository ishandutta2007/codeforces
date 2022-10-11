import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())

    A = []
    for i in range(n):
        for j in range(n):
            if i < j:
                if n & 1 == 0 and i & 1 == 0 and i + 1 == j:
                    A.append(0)
                elif i + j & 1:
                    A.append(1)
                else:
                    A.append(-1)
    print ' '.join(str(a) for a in A)