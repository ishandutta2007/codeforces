n,k=map(int,input().split())
listik=list(map(int,input().split()))
counter,j=0,1
for i in range(2):
    for i in listik:
        if i<=k:
            counter+=1
        else:
            break
    if j==1:
        listik=listik[counter:][::-1]
print(counter)