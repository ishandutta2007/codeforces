a,b=map(int,input().split())
m,n=map(int,input().split())
m1,n1=map(int,input().split())
while b!=0:
    a+=b
    if n1==b:
        a-=m1
    elif n==b:
        a-=m
    a=max(0,a)
    b-=1
print(a)