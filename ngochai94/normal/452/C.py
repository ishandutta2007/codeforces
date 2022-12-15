def c(x,n,k):
    if k<0 or k>n:
        return 0
    elif k>n/2:
        return c(x,n,n-k)
    else:
        for i in range(k):
            x*=n-i
            x/=i+1
        return x
def rvc(x,n,k):
    if k>n/2:
        return rvc(x,n,n-k)
    else:
        for i in range(k):
            x/=n-i
            x*=i+1
        return x
n,m=map(int,raw_input().split())
ans=0.0
for i in range(m):
    a=n-1-i
    b=(n-1)*m
    x=i
    y=m-1
    t=float(i+1)/n
    if t>1:
        t=0
    else:
        for j in range(a):
            t*=b-j
            t/=b+y-j
        for j in range(x):
            t*=y-j
            t/=j+1
            t*=a+1+j
            t/=b+y-a-j
    ans+=t
print ans