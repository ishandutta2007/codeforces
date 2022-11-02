n,m=map(int,input().split())
l=[]
i=1
while i <= n:
    l+=[i]
    i+=m*2+1
if l[-1]<n-m:
    l=[]
    i=n-m
    while i>0:
        l+=[i]
        i-=m*2+1
    print(len(l))
    print(*l[::-1])
else:
    print(len(l))
    print(*l)