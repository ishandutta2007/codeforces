import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
    
n=input()
print f(5,n)*f(3,n)