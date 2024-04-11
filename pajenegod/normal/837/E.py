import sys
range = xrange
input = raw_input

def gcd(a,b):
    while a:
        a, b = b % a, a
    return b

a, b = [int(x) for x in input().split()]

acopy = a
P = []
i = 2
asqrt = int(a**0.5 + 1)
while i <= asqrt:
    if a % i == 0:
        P.append(i)
        while a % i == 0:
            a //= i
    i += 1
if a > 1:
    P.append(a)

a = acopy
count = 0
while b:
    g = gcd(a,b)
    a //= g
    b //= g
    P = [p for p in P if a % p == 0]
    
    rem = min(b % p for p in P) if P else b
    count += rem
    b -= rem
print count