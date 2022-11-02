x=int(input())
listik=list(map(int,input().split()))
listik.sort()
counter=0
for i in range(1,len(listik)):
    if listik[counter]<listik[i]:
        counter+=1
print(counter)