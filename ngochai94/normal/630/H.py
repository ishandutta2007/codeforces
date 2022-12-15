import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
    
n=input()
ans=1
for i in range(5):
    ans*=n
    n-=1
print ans*ans/120