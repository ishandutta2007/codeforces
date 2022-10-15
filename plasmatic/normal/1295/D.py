from math import gcd

def totatives(n):
    phi = int(n > 1 and n)
    for p in range(2, int(n ** .5) + 1):
        if not n % p:
            phi -= phi // p
            while not n % p:
                n //= p
    #if n is > 1 it means it is prime
    if n > 1: phi -= phi // n 
    return phi

for _ in range(int(input())):
    x, m = map(int, input().split())
    print(totatives(m // gcd(x, m)))