n,m=map(int,raw_input().split())
lis=map(int,raw_input().split())
ans=0
for i in range(m):
    ind=map(int,raw_input().split())
    ans+=min(lis[ind[0]-1],lis[ind[1]-1])
print ans