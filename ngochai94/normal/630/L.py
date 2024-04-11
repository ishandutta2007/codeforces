import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
    
n=input()
a=n/10000
n%=10000
b=n/1000
n%=1000
c=n/100
n%=100
d=n/10
e=n%10
n=a*10000+c*1000+e*100+d*10+b
n= (n**5)%100000
a=n/10000
n%=10000
b=n/1000
n%=1000
c=n/100
n%=100
d=n/10
e=n%10
print str(a)+str(b)+str(c)+str(d)+str(e)