import sys
range = xrange
input = raw_input

def gcd(a,b):
    while b:
        a,b = b,a%b
    return a

n = int(input())

A = [i for i in range(1,n) if gcd(i,n) == 1]

prod = 1
for a in A:
    prod = prod * a % n

if prod != 1:
    A.pop()

print len(A)
print ' '.join(str(x) for x in A)