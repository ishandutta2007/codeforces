a,b=map(int,input().split())
l=list(map(int,input().split()))
maxs=0
for i in range(1,b+1):
    lcopy=[]
    lcopy+=l
    for j in range(i,a+1,b):
        lcopy[j-1]=0
    cnt=lcopy.count(1)
    cnt1=lcopy.count(-1)
    maxs=max(maxs,abs(cnt-cnt1))
print(maxs)