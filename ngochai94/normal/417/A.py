x=raw_input().split()
y=raw_input().split()
z=raw_input().split()
c=int(x[0])
d=int(x[1])
n=int(y[0])
m=int(y[1])
k=int(z[0])
if k>=m*n:
    print 0
elif d>c/n:
    rou=(m*n-k)/n
    if k%n==0:
        s=rou*c
        print s
    else:
        s=(rou)*c+((m*n-k)%n)*d
        x=(rou+1)*c
        print min(s,x)
        
else:
    s=(m*n-k)*d
    print s