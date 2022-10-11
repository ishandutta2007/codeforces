import sys
range = xrange
input = raw_input

def gcd(a,b):
    while a:
        a,b = b % a, a
    return b

t = int(input())
for _ in range(t):
    r,b,k = [int(x) for x in input().split()]
    if r > b:
        r,b = b,r


    if gcd(r,b) + r * (k - 1) >= b:
        print 'OBEY'
    else:
        print 'REBEL'
    # 1 + r * k < b
    #k = (b - 1) // r
    #if  >=