n=int(input())
x=list(map(int,input().split()))
x.sort()

nu=0
ans=0

mark=[]
for i in range(0,n):
    mark.append(0)


for i in range(0,n):
    fail=1
    nu=0
    for j in range(0,n):
        if mark[j] == 0:
            fail = 0
            if x[j] >= nu:
                nu+=1
                mark[j]=1
    if fail == 0:
        ans+=1
    else:
        break
print(ans)