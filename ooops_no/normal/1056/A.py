x=int(input())
maybe=list(map(int,input().split()))
maybe=maybe[1:]
maybe.sort()
listik1=[]
for i in range(x-1):
    listik1=list(map(int,input().split()))
    takeit=listik1[0]
    listik1=listik1[1:]
    listik1.sort()
    j=0
    while j<len(maybe):
        if maybe[j] not in listik1:
            maybe.remove(maybe[j])
        else:
            j+=1
    if len(maybe)==1:
        break
print(*maybe)