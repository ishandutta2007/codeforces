import sys
range = xrange
input = raw_input

def gcd(a,b):
    while a:
        a,b = b%a, a
    return b

t = int(input())
for _ in range(t):
    a,m = [int(x) for x in input().split()]

    g = gcd(a,m)
    a //= g
    m //= g

    prodder = m
    p = 2
    while p * p <= m:
        if m % p == 0:
            prodder -= prodder//p
            while m % p == 0:
                m //= p
        p += 1
    if m > 1:
        prodder -= prodder//m

    print prodder