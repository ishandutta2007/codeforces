import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]
n = inp[0]
A = inp[1:]
A.sort()

### Tree
L = [-1, -1]
val = [0, 0]
 
def check(ind):
    if L[ind] == -1:
        L[ind] = len(L)
        L.append(-1)
        L.append(-1)
        val.append(-1)
        val.append(-1)
 
def add(i, ind, bit):
    a = A[i]
    while bit:
        check(ind)
        ind = L[ind] ^ bool(a & bit)
        val[ind] = a
        bit >>= 1
###
 
def solve(bit0, l, r, ind0):
    if not bit0 or l + 2 >= r:
        if l < r:
            val[ind0] = A[l]
            for i in range(l,r):
                add(i, ind0, bit0)
        return 0 if l + 2 != r else A[l] ^ A[l + 1]
    
    Al = A[l]
    Ar = A[r - 1]
    while bit0 and Al & bit0 == Ar & bit0:
        val[ind0] = 1
        check(ind0)
        ind0 = L[ind0] ^ bool(Al & bit0)
        bit0 >>= 1
    
    if not bit0:
        val[ind0] = A[l]
        for i in range(l,r):
            add(i, ind0, bit0)
        return 0

    a = l
    b = r
    while a < b:
        c = a + b >> 1
        if A[c] & bit0:
            b = c
        else:
            a = c + 1
    
    cas = a - l <= r - a
    if cas:
        l1 = l
        r1 = a
        l2 = a
        r2 = r
    else:
        l1 = a
        r1 = r
        l2 = l
        r2 = a
    ans = 0
    val[ind0] = 1
    check(ind0)
    ans += solve(bit0 >> 1, l2, r2, L[ind0] ^ cas)
    
    if l1 != r1:
        best = 1 << 30
        if r2 - l2 >= bit0.bit_length():
            for i in range(l1, r1):
                a = A[i]
                bit = bit0
                ind = ind0
                # find best edge
                while bit:
                    ind = L[ind] ^ bool(a & bit)
                    ind ^= val[ind] == -1
                    bit >>= 1
                best = min(best, val[ind] ^ a)
        else:
            for i in range(l1, r1):
                a = A[i]
                for j in range(l2, r2):
                    if best > a ^ A[j]:
                        best = a ^ A[j]
        ans += best + solve(bit0 >> 1, l1, r1, L[ind0] ^ 1 ^ cas)
    return ans
 
print solve(1 << 29, 0, n, 0)