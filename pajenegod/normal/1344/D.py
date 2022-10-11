import sys,math
range = xrange
input = raw_input

n, k = [int(x) for x in input().split()]
A = [int(x) for x in sys.stdin.read().split()]

# pick as few as possible
def f1(lam):
    s = 0
    for a in A:
        # (b + 1) * (a + lam - (b + 1) ^ 2) - b * (a + lam - b ^ 2)
        def g(b):
            return a + lam - 3 * b * (b + 1)  - 1
        opti = 1/6.0 * (math.sqrt(max(0, 3 * (4 * (a + lam) - 1))) - 3)
        l = min(max(0, int(opti - 0.5)), a)
        r = max(min(a, int(opti + 1.5)), 0)
        while l < r:
            mid = l + r >> 1
            der = g(mid)
            if der > 0:
                l = mid + 1
            else:
                r = mid
        s += l
    return s

# pick as few as possible
def f2(lam):
    B = []
    for a in A:
        # (b + 1) * (a + lam - (b + 1) ^ 2) - b * (a + lam - b ^ 2)
        def g(b):
            return a + lam - 3 * b * (b + 1)  - 1
        
        opti = 1/6.0 * (math.sqrt(max(3 * (4 * (a + lam) - 1),0)) - 3)
        l = min(max(0, int(opti - 0.5)), a)
        r = max(min(a, int(opti + 1.5)), 0)
        while l < r:
            mid = l + r >> 1
            der = g(mid)
            if der > 0:
                l = mid + 1
            else:
                r = mid
        B.append(l)
    return B


a = -4 * 10**18
b = 4 * 10**18
while a < b:
    c = a + b + 1 >> 1
    if f1(c) > k:
        b = c - 1
    else:
        a = c
B = f2(a)
C = f2(a + 1)
k -= sum(B)
for i in range(n):
    extra = min(C[i] - B[i], k)
    k -= extra
    B[i] += extra
import __pypy__, os
out = __pypy__.builders.StringBuilder()
for b in B:
    out.append(str(b))
    out.append(' ')
os.write(1, out.build())