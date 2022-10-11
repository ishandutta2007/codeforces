import sys
import __pypy__
range = xrange
input = raw_input

MOD = 998244353
modmult = __pypy__.intop.int_mulmod
mu = lambda a,b: modmult(a, b, MOD)

big = 3*10**5 + 10
modinv = [1]*big
for i in range(2,big):
    modinv[i] = mu(-(MOD//i), modinv[MOD%i])

n = int(input())
A = [int(x) for x in input().split()]
m = sum(A)

AA = []
BB = []
CC = []
DD = []
for i in range(m):
    a = -mu(i, modinv[m])
    b = 1 - mu(mu(m - i, modinv[m]), mu(n - 2, modinv[n - 1]))
    c = -mu(mu(m - i, modinv[m]), mu(1    , modinv[n - 1]))

    AA.append(a)
    BB.append(b)
    CC.append(c)
    DD.append(1)

def solve(m,A,B,C,D):
    cur = [A[m - 1], B[m - 1], D[m - 1]]
    for i in reversed(range(m - 1)):
        k = mu(-cur[1], pow(C[i], MOD-2, MOD))
        cur = [mu(k, (A[i] if i else 0)), cur[0] + mu(k, B[i]), cur[2] + mu(k, D[i])]
        cur = [c % MOD for c in cur]

    X = [mu(cur[2], pow(cur[1], MOD - 2, MOD))]
    for i in range(m - 1):
        X.append(mu(D[i] - (mu(A[i], X[i - 1]) if i else 0) - mu(B[i], X[i]), pow(C[i], MOD - 2, MOD)))
    
    #ans = [(A[i] * X[i - 1] if i else 0) + B[i] * X[i] + (C[i] * X[i + 1] if i + 1 < m else 0) for i in range(m)]
    #assert ans == D
    return X

F = solve(m, AA, BB, CC, DD)
F.append(0)
num = sum(F[a] for a in A) % MOD - mu(n - 1, F[0])
den = n

print mu(num, pow(den, MOD - 2, MOD))