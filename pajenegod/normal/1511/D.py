import sys
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

n,k = [int(x) for x in input().split()]

used = [0] * k

def gen(k, reversed = False):
    if k == 1:
        return [0]
    A = []
    for i in range(1, k):
        A.append(0)
        A.append(k - i)
    return A

A = []
for i in range(k):
    A += [x + i for x in gen(k - i)]
A += reversed(range(k - 1))

while len(A) < n:
    A = 2 * A

A.insert(0, 0)

print ''.join(chr(ord('a') + x) for x in A[:n])