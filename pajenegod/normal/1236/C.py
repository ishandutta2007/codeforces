import sys
range = xrange
input = raw_input

def f(A,B):
    val = 0
    for a in A:
        for b in B:
            val += a < b
    return val

n = int(input())
A = [[0]*n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if j & 1:
            A[i][j] = (n - 1 - i) + j*n
        else:
            A[i][j] = i + j*n

for a in A:
    print ' '.join(str(x + 1) for x in a)