import math

def d(n,r):
    f = math.factorial
    return f(n) / f(r) / f(n-r)
    
def f(n,r):
    return d(n+r-1,r-1)
def sqrt(x):
    return x**0.5

px,py,vx,vy,a,b,c,d=map(float,raw_input().split())
dx=vx/(vx*vx+vy*vy)**0.5
dy=vy/(vx*vx+vy*vy)**0.5
x=px+dx*b
y=py+dy*b
print '{:.15f}'.format(x),
print '{:.15f}'.format(y)
x=px-dy*a/2
y=py+dx*a/2
print '{:.15f}'.format(x),
print '{:.15f}'.format(y)
x=px-dy*c/2
y=py+dx*c/2
print '{:.15f}'.format(x),
print '{:.15f}'.format(y)
x-=dx*d
y-=dy*d
print '{:.15f}'.format(x),
print '{:.15f}'.format(y)
x+=dy*c
y-=dx*c
print '{:.15f}'.format(x),
print '{:.15f}'.format(y)
x=px+dy*c/2
y=py-dx*c/2
print '{:.15f}'.format(x),
print '{:.15f}'.format(y)
x=px+dy*a/2
y=py-dx*a/2
print '{:.15f}'.format(x),
print '{:.15f}'.format(y)