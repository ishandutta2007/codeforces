a=raw_input().split()
n=int(a[0])
m=int(a[1])
x=int(a[2])
y=int(a[3])
z=int(a[4])
p=int(a[5])
lis=[]
for i in range(p):
    b=raw_input().split()
    c=int(b[0])
    d=int(b[1])
    lis.append((c,d))
def flip(lis,y,p,m):
    for i in range(y%2):
        for k in range(p):
            lis[k]=(lis[k][0],m+1-lis[k][1])
def ro(lis,rot,p,n,m):
    if rot==1:
        for k in range(p):
            lis[k]=(lis[k][1],n+1-lis[k][0])
    if rot==2:
        for k in range(p):
            lis[k]=(n+1-lis[k][0],m+1-lis[k][1])
    if rot==3:
        for k in range(p):
            lis[k]=(m+1-lis[k][1],lis[k][0])
ro(lis,x%4,p,n,m)
if x%2==1:
    n,m=m,n
flip(lis,y,p,m)
ro(lis,(0-z)%4,p,n,m)
for i in lis:
    print i[0], i[1]