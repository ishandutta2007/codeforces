import sys

def gcd(a, b):
    if b==0:
        return a
    else:
        return gcd(b, a%b)

    
p,q = map(int, sys.stdin.readline().split(' '))
n = int(sys.stdin.readline())
a = map(int, sys.stdin.readline().split(' '));

nu=1
de=0
for i in range(1,n+1):
    tmp = nu
    nu = a[n-i] *nu + de
    de = tmp
    g = gcd(de, nu)
    de /= g
    nu /= g

g = gcd(p, q)
p /= g
q /= g
if p==nu and q==de:  
    print "YES"
else:
    print "NO"