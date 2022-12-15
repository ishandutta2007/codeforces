import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
def sqrt(x):
    return x**0.5


a,b,c=map(int,raw_input().split())
alp=math.pi/180*36
ans=2**0.5/12*a**3+2**0.5/6*b**3+5.0/24*c**3/(math.tan(alp))*2*(1-1/(4*(math.sin(alp))**2))**0.5
print '{:.15f}'.format(ans)