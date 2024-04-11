import sys
range = xrange
input = raw_input

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
w = inp[ii]; ii += 1

X = inp[ii + 0: ii + 2 * n: 2]
V = inp[ii + 1: ii + 2 * n: 2]
V = [-v for v in V]
ii += 2 * n

def sign(x):
    return 1 - 2*(x < 0)

def cmp1(i,j):
    # X[i] / (V[i] - w) < X[j] / (V[j] - w)
    a = X[i]
    b = V[i] - w

    c = X[j]
    d = V[j] - w

    x = sign(b) * a * abs(d)
    y = sign(d) * c * abs(b)

    return -(x < y or (x == y and 1.0 / b < 1.0 / d))

def cmp2(i,j):
    # X[i] / (V[i] + w) < X[j] / (V[j] + w)
    a = X[i]
    b = V[i] + w

    c = X[j]
    d = V[j] + w

    x = sign(b) * a * abs(d)
    y = sign(d) * c * abs(b)

    return -(x < y or (x == y and 1.0 / b > 1.0 / d))

order1 = sorted(range(n), cmp = cmp1)
order2 = sorted(range(n), cmp = cmp2)

def invert_count(A, B):
    mapper = [0]*n
    for i in range(n):
        mapper[A[i]] = i

    order = [mapper[i] for i in B]
    
    class segtree:
        def __init__(self, n):
            m = 1
            while m < n: m*=2
            self.m = m
            self.data = [0]*(2*m)
        def add(self, i):
            i += self.m
            while i:
                self.data[i] += 1
                i >>= 1
        def summer(self, l, r):
            l += self.m
            r += self.m

            s = 0
            while l < r:
                if l & 1:
                    s += self.data[l]
                    l += 1
                if r & 1:
                    r -= 1
                    s += self.data[r]
                l >>= 1
                r >>= 1
            return s

    seg = segtree(n)
    s = 0
    for i in reversed(order):
        s += seg.summer(0, i)
        seg.add(i)
    return s

print invert_count(order1, order2)