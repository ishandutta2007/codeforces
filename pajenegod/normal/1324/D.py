import sys
range = xrange
input = raw_input

n = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]

C = [A[i] - B[i] for i in range(n)]
# i < j and C[i] + C[j] > 0
C.sort()

ans = - sum(c > 0 for c in C)
for i in range(n):
    a = i
    b = n
    while a < b:
        c = a + b >> 1
        if C[i] + C[c] > 0:
            b = c
        else:
            a = c + 1
    ans += n - a

print ans