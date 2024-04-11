n=input()-1
f=lambda x:x<2or x*f(x-1)
print f(n)/(n/2+1)