import sys
range = xrange
input = raw_input

MOD = 10**9 + 7
INVMOD = 1.0/MOD
import __pypy__
mulmod = __pypy__.intop.int_mulmod
sub = __pypy__.intop.int_sub
mul = __pypy__.intop.int_mul

def mo(a,b):
    return sub(mul(a,b), mul(MOD, int(INVMOD * a * b)))


n = int(input())
A = []
for _ in range(n):
    A.append([int(x) for x in input().split()])

# don't connect ends
DP0 = [[-1] * n for _ in range(n)]
# connect ends
DP1 = [[-1] * n for _ in range(n)]

for i in range(n):
    DP0[i][0] = 1
    DP1[i][0] = 1

for l in range(1, n):
    for i in range(n):
        Ai = A[i]
        DP0i = DP0[i]
        DP1i = DP1[i]
        
        x = 0.0 + DP1[i + 1 - n][l - 1]
        for k in range(1, l):
            if Ai[i + k - n]:
                x += mo(DP0i[k], DP0[i + k - n][l - k])
        DP0i[l] = int(int(x) % MOD)

        x = 0.0
        for k in range(1, l + 1):
            if Ai[i + k - n]:
                x += mo(DP0i[k], DP1[i + k - n][l - k])
        DP1i[l] = int(int(x) % MOD)

print DP1[0][n - 1]