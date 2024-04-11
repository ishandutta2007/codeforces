n,m=map(int,input().split())
a=input()
b=[(i)for i in input().split()]
cou=0
cou1=0
ans=0
while cou<n:
    if a[cou] not in b:
        ans+=cou1*(cou1+1)/2
        cou1=0
    elif cou==n-1:
        cou1+=1
        ans += cou1 * (cou1 + 1) / 2
    else:
        cou1+=1
    cou+=1
print(int(ans))