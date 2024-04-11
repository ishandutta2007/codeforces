import sys
range = xrange
input = raw_input

MOD = 10**9 + 7

import __pypy__
modmul = __pypy__.intop.int_mulmod
mo = lambda a,b: modmul(a,b,MOD)
modinv = lambda a: pow(a, MOD - 2, MOD)

n = int(input())
L = [int(x) for x in input().split()]
R = [int(x) for x in input().split()]

I = []
I2 = []
for i in range(n - 1):
    l1 = L[i]
    r1 = R[i] + 1
    inv1 = modinv(r1 - l1)

    l2 = L[i + 1]
    r2 = R[i + 1] + 1
    inv2 = modinv(r2 - l2)

    l = max(l1,l2)
    r = min(r1,r2)
    inv = mo(inv1, inv2)

    I.append(mo(r - l, inv) if l < r else 0)
    if i < n - 2:
        l3 = L[i + 2]
        r3 = R[i + 2] + 1
        inv3 = modinv(r3 - l3)
        
        l = max(l, l3)
        r = min(r, r3)
        inv = mo(inv, inv3)
        I2.append(mo(r - l, inv) if l < r else 0)

Icumsum = [0]
for i in I:
    Icumsum.append((Icumsum[-1] + i) % MOD)

extra = 0
for i in range(n - 2):
    extra += I2[i] + mo(I[i], Icumsum[-1] - Icumsum[i + 2])
    

ans = n * n + (- 2 * n + 1) * Icumsum[-1] + 2 * extra
print ans % MOD