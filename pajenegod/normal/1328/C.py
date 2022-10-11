import sys
range = xrange
input = raw_input

t = int(input())
for _ in range(t):
    n = int(input())
    X = [int(c) for c in input()]
    X.pop(0)
    A = [1]
    B = [1]

    switched = False

    for c in X:
        if c == 0:
            A.append(0)
            B.append(0)
        elif c == 1:
            A.append(1)
            B.append(0)
            if not switched:
                switched = True
                A,B = B,A
        else:
            if not switched:
                A.append(1)
                B.append(1)
            else:
                A.append(2)
                B.append(0)

    print ''.join(str(x) for x in A)
    print ''.join(str(x) for x in B)