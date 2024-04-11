t=int(input())
while t>0:
    t-=1
    a,b=map(int,input().split())
    c,d=map(int,input().split())
    if (a==c and a==b+d)or(a==d and a==b+c)or(b==c and b==a+d)or(b==d and b==a+c):
        print("YES")
    else:
        print("NO")