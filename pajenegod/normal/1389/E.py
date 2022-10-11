import sys, collections
range = xrange
input = raw_input

def gcd(a,b):
    if a == 0:
        return b
    while b:
        a,b = b,a%b
    return a

def solve1(N, Y, MOD):
    counter = collections.defaultdict(int)
    total = 0
    for dig in range(N):
        val = dig * Y % MOD
        total += counter[val]
        counter[val] += 1
    return total

def solve2(N, Y, MOD):
    counter = collections.defaultdict(int)
    total = 0
    MOD //= gcd(Y, MOD)
    for dig in range(N):
        val = dig % MOD
        total += counter[val]
        counter[val] += 1
    return total

def solve2(N, Y, MOD):
    MOD //= gcd(Y, MOD)
    
    A = N % MOD
    B = MOD - A
    Acount = (N // MOD) + 1
    Bcount = (N // MOD)

    first = A * Acount * (Acount - 1)//2
    second = B * Bcount * (Bcount - 1)//2
    return first + second

t = int(input())
for _ in range(t):
    m,d,w = [int(x) for x in input().split()]
    
    digits = min(m ,d)
    print solve2(digits, d - 1, w)