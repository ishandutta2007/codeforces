import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
def sqrt(x):
    return x**0.5

n,r=map(int,raw_input().split())
alp=math.pi/n
x=math.sin(alp)/math.sin(1.5*alp)*2*r*math.cos(alp/2)
ans=n*(x-r)*r*math.sin(alp)
print '{:.15f}'.format(ans)