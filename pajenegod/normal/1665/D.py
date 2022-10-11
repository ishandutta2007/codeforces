import sys
import random

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

def query(a,b):
    assert 1 <= a <= 2*10**9
    assert 1 <= b <= 2*10**9
    assert a != b

    print("?", a, b)
    ans = int(input())
    
    #x = 1000000000
    #ans = gcd(a + x, b + x)

    #print('gcd(%d + %d, %d + %d) = %d' % (x, a, x, b, ans) )
    return ans


pow2 = 2**30

t = int(input())
for cas in range(t):
    known_bits = 0
    a = 1

    iterations = 0
    while known_bits <= 10**9:
        iterations += 1
        
        # b - a = power of 2
        b = pow2 + a
        
        ans = query(a,b)

        known_bits = 2 * ans - 1
        a ^= 1 << (known_bits.bit_length() - 1)
        if a == 0:
            a ^= 1 << (known_bits.bit_length() - 0)
        

    # x + a == 0 mod 2^30

    x = (pow2 - a) % pow2 
    print("!", x)