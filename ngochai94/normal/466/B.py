n,a,b=map(int,raw_input().split())
n*=6
flag=False
if a>b:
    a,b=b,a
    flag=True
a,b=min(a,b),max(a,b)
a1,b1=a,b
s=10**18
for i in range(a,1+int(n**0.5)):
    j=max(b1,1+(n-1)/i)
    if i*j<s:
        s=i*j
        a,b=i,j
print a*b
if flag:
    print b,a
else:
    print a,b