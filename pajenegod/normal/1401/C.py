import sys
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

t = int(input())
for _ in range(t):
    n = int(input())
    A = [int(x) for x in input().split()]
    Amin = min(A)

    I = [+(gcd(Amin, a) == Amin) for a in A]

    B = [A[i] for i in range(n) if I[i]]
    C = [A[i] for i in range(n) if not I[i]]

    B.sort()

    B.reverse()
    C.reverse()

    D = []
    for i in range(n):
        if I[i]:
            D.append(B.pop())
        else:
            D.append(C.pop())

    print 'YES' if sorted(D) == D else 'NO'