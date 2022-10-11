import sys
range = xrange
input = raw_input

k1,k2,k3 = [int(x) for x in input().split()]

t1,t2,t3 = [int(x) for x in input().split()]

n = int(input())
C = [int(x) for x in input().split()]


def move(C, k, t):
    T = []

    i = 0
    j = 0
    for c in C:
        while i < j and T[i] <= c:
            i += 1
        if j - i < k:
            dt = c
        else:
            dt = max(c, T[j - k])
        T.append(dt + t)
        j += 1
            
    return T

A = move(C,k1,t1)
B = move(A,k2,t2)
D = move(B,k3,t3)

print max(D[i] - C[i] for i in range(n))