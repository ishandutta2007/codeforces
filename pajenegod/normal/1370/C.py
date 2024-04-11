import sys
range = xrange
input = raw_input

def solve(n):
    if n == 1:
        return False
    if n & 1:
        return True
    if n == 2:
        return True
    if n % 4 != 0:
        n //= 2
        i = 3
        while i * i <= n:
            if n % i == 0:
                return True
            i += 1
        return False
    return n != (1 << n.bit_length() - 1)

t = int(input())
for _ in range(t):
    n = int(input())
    print 'Ashishgup' if solve(n) else 'FastestFinger'