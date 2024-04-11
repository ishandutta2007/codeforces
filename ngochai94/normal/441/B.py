n,v=map(int,raw_input().split())
lis=[0]*3005
for i in range(n):
    a,b=map(int,raw_input().split())
    lis[a]+=b
ans=0
for i in range(1,3005):
    go=min(v,lis[i-1]+lis[i])
    lis[i]-=max(0,go-lis[i-1])
    ans+=go
print ans