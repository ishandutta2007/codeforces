import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
def sqrt(x):
    return x**0.5


n=input()
n=n%360
if n<=45 or n>=315 :
    print 0
elif n>45 and n<=135:
    print 1
elif n>135 and n<=225:
    print 2
else:
    print 3