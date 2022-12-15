import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
n=input()
print d(n,5)+d(n,6)+d(n,7)