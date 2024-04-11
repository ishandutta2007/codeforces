import sys
range = xrange
input = raw_input
from collections import defaultdict as di

inp = [int(x) for x in sys.stdin.read().split()]; ii = 0

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

def lcm(a,b):
    return a // gcd(a,b) * b


def solve(n,k):
    N = n//2

    A = []
    while k > 3:
        A.append(1)
        k -= 1
        n -= 1
    
    if n % 2 == 0:
        for tests in [n//3, n//3, n//3],:
            if sum(tests) != n:
                continue
            p = 1
            for a in tests:
                p = lcm(p, a)
            if p <= n // 2:
                break
        else:
            y = 1
            while True:
                x = 1 << y
                tests = [x, (n - x)//2, (n - x)//2]
                p = 1
                for a in tests:
                    p = lcm(p, a)
                if p <= n // 2:
                    break
                y += 1
        A += tests
        k -= 3
    else:
        A.append(1)
        k -= 1
        n -= 1

    while k:
        A.append(n//2)
        k -= 1
    return A

t = inp[ii]; ii += 1
for _ in range(t):
    n,k = inp[ii: ii + 2]; ii += 2
    A = solve(n,k)
    print ' '.join(str(x) for x in A)