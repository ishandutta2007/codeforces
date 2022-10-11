import sys
range = xrange
input = raw_input

from collections import Counter

def memodict(f):
    """memoization decorator for a function taking a single argument"""
    class memodict(dict):
        def __missing__(self, key):
            ret = self[key] = f(key)
            return ret

    return memodict().__getitem__


def pollard_rho(n):
    """returns a random factor of n"""
    if n & 1 == 0:
        return 2
    if n % 3 == 0:
        return 3

    s = ((n - 1) & (1 - n)).bit_length() - 1
    d = n >> s
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        p = pow(a, d, n)
        if p == 1 or p == n - 1 or a % n == 0:
            continue
        for _ in range(s):
            prev = p
            p = (p * p) % n
            if p == 1:
                return gcd(prev - 1, n)
            if p == n - 1:
                break
        else:
            for i in range(2, n):
                x, y = i, (i * i + 1) % n
                f = gcd(abs(x - y), n)
                while f == 1:
                    x, y = (x * x + 1) % n, (y * y + 1) % n
                    y = (y * y + 1) % n
                    f = gcd(abs(x - y), n)
                if f != n:
                    return f
    return n

@memodict
def prime_factors(n):
    """returns a Counter of the prime factorization of n"""
    if n <= 1:
        return Counter()
    f = pollard_rho(n)
    return Counter([n]) if f == n else prime_factors(f) + prime_factors(n // f)

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

def prime_divisors(x):
    count = prime_factors(x)
    return sum(count[x] for x in count)

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

t = inp[ii]; ii += 1
for _ in range(t):
    a,b,k = inp[ii: ii + 3]; ii += 3

    g = gcd(a,b)
    a //= g
    b //= g

    a = prime_divisors(a)
    b = prime_divisors(b)

    if (a > 0) + (b > 0) <= k <= a + b:
        print 'YES'
    else:
        g = prime_divisors(g)
        a += g
        b += g
        if (a > 0) + (b > 0) <= k <= a + b:
            print 'YES'
        else:
            print 'NO'