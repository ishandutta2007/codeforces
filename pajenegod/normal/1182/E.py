import sys
range = xrange
input = raw_input

MOD = 10**9 + 7
primitive = 5

# solves primiteive**y == x in sqrt(mod) time
def disc_log(x):
    m = int(MOD**.5 + 1)

    found = set()
    y = 1
    for i in range(m + 1):
        found.add(y)
        y = y * primitive % MOD
    
    fac = pow(primitive, MOD - 2, MOD)
    fac = pow(fac, m, MOD)

    y = 1
    for j in range(m + 1):
        if x * y % MOD in found:
            break
        y = y * fac % MOD

    goal = x * y % MOD

    y = 1
    for i in range(m + 1):
        if y == goal:
            break
        y = y * primitive % MOD
    
    return j * m + i

def matmult(A, B):
    n = len(A)
    m = len(B[0])
    w = len(A[0])
    C = [[0]*n for _ in range(m)]

    for i in range(n):
        for k in range(w):
            for j in range(m):
                C[i][j] += A[i][k] * B[k][j]
    for i in range(n):
        for j in range(m):
            C[i][j] %= MOD - 1
    return C

def matpow(A, m):
    n = len(A)
    Ak = [[0]*n for _ in range(n)]
    for i in range(n):
        Ak[i][i] += 1
    
    if m == 0:
        return Ak 
    while m > 1:
        if m & 1:
            Ak = matmult(A, Ak)
        A = matmult(A, A)
        m >>= 1
    return matmult(A, Ak)


mat = [[1,1,1,1,0],
       [1,0,0,0,0],
       [0,1,0,0,0],
       [0,0,0,1,1],
       [0,0,0,0,1]]

n,f1,f2,f3,c = [int(x) for x in input().split()]
c = pow(c, 2, MOD)
logf1,logf2,logf3,logc = map(disc_log, (f1,f2,f3,c))

mat = matpow(mat, n - 3)
vec = [logf3, logf2, logf1, logc, logc]

print pow(primitive, sum(a*b for a,b in zip(mat[0], vec)), MOD)