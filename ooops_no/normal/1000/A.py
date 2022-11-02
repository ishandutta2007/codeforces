x=int(input())
listik=[]
for _ in range(x):
    listik+=[input()]
listik.sort()
listik2=[]
for _ in range(x):
    listik2+=[input()]
listik2.sort()
counter=0
for i in range(x):
    if listik[i] not in listik2:
        counter+=1
    else:
        listik2.remove(listik[i])
print(counter)