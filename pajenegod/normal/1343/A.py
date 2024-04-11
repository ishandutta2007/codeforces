import sys
range = xrange
input = raw_input

def is2pow(x):
    return x != 0 and (x - 1) & x == 0

t = int(input())
for _ in range(t):
    n = int(input())

    y = 1
    while y * y <= n:
        if n % y == 0:
            x = n // y
            if is2pow(x + 1):
                k = (x + 1).bit_length() - 1
                if k > 1:
                    print y
                    break
            if is2pow(y + 1):
                k = (y + 1).bit_length() - 1
                if k > 1:
                    print x
                    break
            x = n//y
            
        y += 1