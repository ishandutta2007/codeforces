n,m=map(int,input().split())
listik=list(map(int,input().split()))
counter=1
maxs=0
for i in range(n-1):
    if listik[i]!=listik[i+1]:
        counter+=1
    else:
        maxs=max(maxs,counter)
        counter=1
maxs=max(counter,maxs)  
print(maxs)