import sys, __pypy__
range = xrange
input = raw_input

MOD = 998244353
mulmod = __pypy__.intop.int_mulmod

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

D = inp[ii]; ii += 1
q = inp[ii]; ii += 1

U = inp[ii + 0: ii + 2 * q: 2]
V = inp[ii + 1: ii + 2 * q: 2]

Pdiv = []
if D & 1 == 0:
    Pdiv.append(2)
    while D & 1 == 0:
        D >>= 1

i = 3
while i * i <= D:
    if D % i == 0:
        while D % i == 0:
            D //= i
        Pdiv.append(i)
    i += 2
if D > 1:
    Pdiv.append(D)


fac = [1]
for i in range(1,200):
    fac.append(mulmod(fac[-1], i, MOD))
ifac = [pow(f, MOD-2, MOD) for f in fac]

def multi(A):
    prod = fac[sum(A)]
    for a in A:
        prod = mulmod(prod, ifac[a], MOD)
    return prod

out = []
for _ in range(q):
    u = U[_]
    v = V[_]
    if u > v:
        v,u = u,v

    add = []
    rem = []

    for p in Pdiv:
        cu = 0
        while u % p == 0:
            u //= p
            cu += 1

        cv = 0
        while v % p == 0:
            v //= p
            cv += 1

        if cu > cv:
            rem.append(cu - cv)
        elif cu < cv:
            add.append(cv - cu)
    out.append(mulmod(multi(add), multi(rem), MOD))

print '\n'.join(str(x) for x in out)