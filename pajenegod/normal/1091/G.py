import sys,random
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        a,b = b, a%b
    return a

n = N = int(input())

def is_prime(n):
    """returns True if n is prime else False"""
    if n < 5 or n & 1 == 0 or n % 3 == 0:
        return 2 <= n <= 3
    s = ((n - 2) ^ (n - 1)).bit_length() - 1
    d = n >> s
    for a in [2, 325, 9375, 28178, 450775, 9780504, 1795265022]:
        p = pow(a, d, n)
        if p == 1 or p == n - 1 or a % n == 0: continue
        for _ in range(s):
            p = (p * p) % n
            if p == n - 1: break
        else:
            return False
    return True


def factor(n):
    if is_prime(n):
        return {n}
    f = set()
    for i in range(20):
        x = random.randrange(n)
        print 'sqrt',x*x%N
        y = int(input())
        
        a = (x-y)%n
        g = gcd(n, a)
        if 1<g<n:
            f |= factor(g)
            f |= factor(n//g)
            return f
    f.add(n)
    return f


f = factor(n)
print '!',len(f),' '.join(str(x) for x in sorted(f))