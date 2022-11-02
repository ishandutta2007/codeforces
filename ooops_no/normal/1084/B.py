a,b=map(int,input().split())
l=list(map(int,input().split()))
summa=sum(l)
need=0
if summa<b:
    print(-1)
elif summa==b:
    print(0)
else:
    need=summa-b
    print(min(min(l),need//a))