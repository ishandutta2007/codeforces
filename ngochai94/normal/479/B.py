n,k=map(int,raw_input().split())
lis=map(int,raw_input().split())
ans=[]
for _ in range(k):
    high=0
    low=10**7
    inhi=inlo=0
    for i in range(n):
        if lis[i]>high:
            high=lis[i]
            inhi=i
        if lis[i]<low:
            low=lis[i]
            inlo=i
    if high-low<=1:
        break
    ans.append((inhi+1,inlo+1))
    lis[inhi]-=1
    lis[inlo]+=1
print max(lis)-min(lis),len(ans)
for i in ans:
    print i[0],i[1]