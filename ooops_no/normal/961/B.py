n,m=map(int,input().split())
l=list(map(int,input().split()))
l1=list(map(int,input().split()))
l2=[]
sums=0
need=0
for i in range(n):
    if l1[i]==1:
        need+=l[i]
for i in range(m):
    if i<m:
        if l1[i]==0:
            l2+=[l[i]]
            sums+=l[i]
        else:
            l2+=[0]
maxs=sums
for j in range(i+1,n):
    sums-=l2[0]
    del l2[0]
    if l1[j]==0:
        l2+=[l[j]]
        sums+=l[j]
    else:
        l2+=[0]
    maxs=max(maxs,sums)
print(maxs+need)