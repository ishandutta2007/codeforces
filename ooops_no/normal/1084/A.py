x=int(input())
l=[0]+list(map(int,input().split()))
level=l.index(max(l))
counter=0
maxs=99999999999999999999999999
for i in range(x+1):
    if l[i]>=1:
        level=i
        for i in range(2,x+1):
            counter+=abs(level-i)*2*l[i]
            counter+=+abs(level-1)*2*l[i]
            counter+=(i-1)*l[i]*2
        maxs=min(counter,maxs)
print(maxs)