import sys
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        a,b = b, a%b
    return a

def lcm(a,b):
    return a // gcd(a,b) * b

t = int(input())
for _ in range(t):
    l,r = [int(x) for x in input().split()]
    a,b = (-1, -1) if 2 * l > r else (l, 2 * l)
    print a,b