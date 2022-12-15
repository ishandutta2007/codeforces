n,m=map(int,raw_input().split())
lis=map(int,raw_input().split())
ans=1
sp=m
while lis!=[]:
    if sp<lis[0]:
        sp=m
        ans+=1
    else:
        sp-=lis[0]
        lis=lis[1:]
print ans