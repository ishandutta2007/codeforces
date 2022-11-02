x=int(input())
a=list(map(int,input().split()))
v=min(a)
minimum=a.count(v)
x=max(a)
maximum=a.count(x)
if v==x:
    x=0
    for i in range(minimum):
        x+=i
    print(0,x)
else:
    print(x-v,minimum*maximum)