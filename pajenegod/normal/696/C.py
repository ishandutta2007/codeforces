import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

def mult(A, B):
    return [
            (A[0]*B[0] + A[1] * B[2]) % MOD,
            (A[0]*B[1] + A[1] * B[3]) % MOD,
            (A[2]*B[0] + A[3] * B[2]) % MOD,
            (A[2]*B[1] + A[3] * B[3]) % MOD
            ]

A = [1, 1, 2, 0]

inp = sys.stdin.read().split()
ii = 0

k = int(inp[ii])
ii += 1


if all(a == '1' for a in inp[ii:]):
    print '0/1'
    sys.exit()

prod = 1
for _ in range(k):
    a = int(inp[ii]) % (MOD - 1)
    ii += 1
    prod = prod * a % (MOD - 1)

if prod > 0:
    pow2 = 2
    base = 1
    B = [1, 0, 0, 1]
    while prod > 1:
        if prod & 1:
            B = mult(A, B)
            base = base * pow2 % MOD
        A = mult(A, A)
        pow2 = pow2 * pow2 % MOD
        prod >>= 1
    A = mult(A, B)
    pow2 = pow2 * base % MOD
else:
    A = [1, 0, 0, 1]
    pow2 = 1


denom = pow2 * (MOD + 1 >> 1) % MOD 
nume = A[3] * (MOD + 1 >> 1) % MOD 

print '%d/%d' % (nume,denom)