n=input()
x=int((-1+(8*n)**0.5)/2)
if x*(x+1)/2==n:
    print x
else:
    print n-x*(x+1)/2