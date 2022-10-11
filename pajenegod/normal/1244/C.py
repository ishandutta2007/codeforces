import sys
range = xrange
input = raw_input

n,p,w,d = [int(x) for x in input().split()]

# x+y+z = n
# x * w + y * d = p

def xgcd(a, b):
    """return (g, x, y) such that a*x + b*y = g = gcd(a, b)"""
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a != 0:
        q, b, a = b // a, a, b % a
        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
    return b, x0, y0

def sign(x):
    return 1 if x >= 0 else -1

g,x,y = xgcd(w,d)


if p % g != 0:
    print -1
else:
    p //= g

    x *= p
    y *= p

    x0 = d // g
    y0 = w // g

    # x0 < y0
    # y - k * y0 >= 0
    k = y//y0

    x += k * x0
    y -= k * y0

    if x < 0:
        # x + k * x0 >= 0
        k = (-x + x0 - 1)//x0
        x += k * x0
        y -= k * y0


    if 0 <= x and 0 <= y and x + y <= n:
        print x,y,n - x - y
    else:
        print -1