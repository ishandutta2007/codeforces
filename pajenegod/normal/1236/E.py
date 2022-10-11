import sys
range = xrange
input = raw_input

n,m = [int(x) for x in input().split()]

if n == 1 and m > 0:
    print 0
    sys.exit()

A = [int(x) for x in input().split()]

def solve(A):
    B = [0]*(n + m + 4)
    B[:n] = [1]*n

    dx = 1
    B[n - 1 - dx] += B[n - dx]
    B[n - dx] = 0
    
    for a in A:
        B[a - 2 - dx] += B[a - 1 - dx]
        B[a - 1 - dx] = 0

        dx += 1
        B[n - 1 - dx] += B[n - dx]
        B[n - dx] = 0

    reach = []
    for i in range(n):
        reach += [i]*B[i - dx]
    return reach

R = solve(A)
L = [n - 1 - i for i in reversed(solve(A[::-1]))]

ans = 0
for i in range(n):
    ans += R[i] - L[i] + 1

print ans