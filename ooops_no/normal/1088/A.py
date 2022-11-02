x=int(input())
sqrt=int(x**0.5)+1
a=sqrt
b=sqrt
if a<=x and b<=x and a/b<x and a*b>x:
    print(a,b)
else:
    print(-1)