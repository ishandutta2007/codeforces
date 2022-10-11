import sys
range = xrange

# n log n time and memory precalc,
# then answers queries in O(1) time
class Queries:
    def __init__(self, A, f = lambda a,b: a + b, max_d = float('inf')):
        self.f = f
        self.lists = [A]
        n = len(A)
        for d in range(1, min(n.bit_length(), max_d + 1)):
            tmp = list(A)
            self.lists.append(tmp)
            x = (1 << d) + 1
            jump = x + 1
            I = (1 << d + 1) - 1
            while x < n:
                tmp[x]     = f(tmp[x - 1], tmp[x])
                tmp[x ^ I] = f(tmp[x ^ I], tmp[x - 1 ^ I])
                x += 1 if ~x & I else jump
            if x == n:
                while x & I:
                    tmp[x ^ I] = f(tmp[x ^ I], tmp[x - 1 ^ I])
                    x += 1

    def __call__(self, a, b):
        tmp = self.lists[(a ^ b - 1).bit_length() - 1]
        return self.f(tmp[a], tmp[b - 1]) if a - b + 1 else self.lists[0][a]

# n log log n time and memory precalc
# then answers queries in O(1) time
class Queries2:
    def __init__(self, A, f = lambda a,b: a + b):
        self.f = f
        self.c = Queries(A, f, 3).__call__
        
        n = len(A)
        self.p = prefix = list(A)
        self.s = suffix = list(A)
        i = 17
        while i < n:
            prefix[i] = f(prefix[i - 1], prefix[i])
            i += 1 + (~i & 15 == 0)
        i = n - 2 if n - 2 & 15 != 15 else n - 3
        while i >= 0:
            suffix[i] = f(suffix[i], suffix[i + 1])
            i -= 1 + (i & 15 == 0)
        self.k = Queries(suffix[:-16: 16], f).__call__

    def __call__(self, a, b):
        if a ^ b - 1 < 16: 
            return self.c(a, b)
        return self.f(self.f(self.s[a], self.k((a >> 4) + 1, b - 1 >> 4)) if (a >> 4) + 1 < b - 1 >> 4 else self.s[a], self.p[b - 1])

def gcd(a,b):
    while a:
        a,b = b % a, a
    return b

def merge((val1, count1), (val2, count2)):
    g = gcd(val1, val2)
    if g == val1 == val2:
        return g, count1 + count2
    elif g == val1:
        return g, count1
    elif g == val2:
        return g, count2
    else:
        return g, 0

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

n = inp[ii]; ii += 1
S = inp[ii: ii + n]; ii += n

RQ = Queries2([(s,1) for s in S], merge)

t = inp[ii]; ii += 1
out = []
for _ in range(t):
    l = inp[ii] - 1; ii += 1
    r = inp[ii]; ii += 1

    out.append(r - l - RQ(l,r)[1])
print '\n'.join(str(x) for x in out)