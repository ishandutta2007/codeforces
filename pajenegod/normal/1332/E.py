import sys
range = xrange
input = raw_input

MOD = 998244353

n,m,L,R = [int(x) for x in input().split()]
R += 1

if (n * m) & 1:
    print pow(R - L, m * n, MOD)
    sys.exit()

even = 0
odd = 0
if L & 1:
    odd += 1
    L += 1

even += (R - L + 1) >> 1
odd += (R - L) >> 1

def multer(A,B):
    C =    [
            A[0] * B[0] + A[1] * B[2],
            A[0] * B[1] + A[1] * B[3],
            A[2] * B[0] + A[3] * B[2],
            A[2] * B[1] + A[3] * B[3]
           ]
    return [c%MOD for c in C]

def power(A, k):
    ans = [1,0,0,1]
    while k:
        if k & 1:
            ans = multer(ans, A)
        A = multer(A,A)
        k >>= 1
    return ans

ans = power([even, odd, odd, even], n * m)
print ans[3] % MOD