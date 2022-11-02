x=int(input())
listik=list(map(int,input().split()))
counter=0
for i in range(1,x-1):
    if listik[i]==0 and listik[i-1]==1 and listik[i+1]==1:
        listik[i+1]=0 
        listik[i-1]=0
        counter+=1
print(counter)