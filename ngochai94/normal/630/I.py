import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
def sqrt(x):
    return x**0.5


n=input()
print 4*(6*4**(n-3)+9*(n-3)*4**(max(0,n-4)))