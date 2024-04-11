import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
def sqrt(x):
    return x**0.5
a,b,c=map(int,raw_input().split())
d=b*b-4*a*c;
x=(-b+sqrt(d))/(2*a);
xx=(-b-sqrt(d))/(2*a);
print '{:.15f}'.format(max(x,xx))
print '{:.15f}'.format(min(x,xx))